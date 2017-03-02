/**
 * A simple non-preemptive CPU Scheduler simulator
 * @author Bryan Stamey
 * @since 02-16-2017
 * Course: CSC3102.01
 * Programming Project #: 1
 * Instructor: Dr. Duncan
 * @see PCB.h, Heap.cpp. Heap.h
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Heap.cpp"
#include "PCB.h"
#include <random>

using namespace std;


int main(int argc, char** argv)
{
    //initialize initial counters, heap, etc.
    Heap<PCB> scheduleHeap;             //initialize Heap of PCB objects
    srand(time(NULL));                  //seeds generator to time
    double p = atof(argv[1]);           //probability of creation
    int id = 0;                         //pid counter
    int exeProcesses = 0;               //# of processes executed
    float totWait;                      //total wait time
    
    //start loop for given # of slices
    for (int s = 1; s <= atoi(argv[2]); s ++) {     //argv[2] = # of slices
        
        //generate q
        cout << "*** Cycle #: " << s << " ***\n";   //output cycle #
        std::random_device rd;
        std::default_random_engine generator(rd()); //rd() provides a random seed
        std::uniform_real_distribution<double> distribution(0.0,1);
        double q = distribution(generator);         //q in range [0, 1]

        //create PCB and insert in heap
        if ( q <= p ) {                             //q <= p job is created
            id ++;                                  //iterate for created PCB
            int pVal = (rand() % 40) - 20;          //priority in range -20 to 19
            int len = rand() % 100 + 1;             //length in range 1 to 100
            PCB pcb(id, pVal, 0, s, len);           //initialize PCB object
            scheduleHeap.insert(pcb);               //insert PCB into heap
            cout << "Adding job with pid # " << id << " and priority " << pVal << " and length " << len << ".\n";
        }
        
        //no job is added
        else {
            cout << "No new job added this cycle.\n";
        }

        //check that heap isn't empty
        if (scheduleHeap.isEmpty() == false) {
            //check for termination
            if (s - scheduleHeap.peek().getLength() == scheduleHeap.peek().getStart()) {
                totWait += scheduleHeap.peek().getWait();   //add wait time
                //output termination and remove from scheduleHeap
                cout << "Process # " << scheduleHeap.remove().getPid() << " has just terminated.\n";
            }

            //if heap not empty & execution status of top set to zero
            if (scheduleHeap.peek().isExecuting() == 0) {
                PCB temp = scheduleHeap.remove();       //remove from top of scheduleHeap
                temp.setStart(s + 1);                   //set start for next cycle
                temp.execute();                         //set execution
                //set wait time = start time - arrival time
                temp.setWait(temp.getStart() - temp.getArrival());
                scheduleHeap.insert(temp);              //reinsert to heap
                exeProcesses ++;                        //increment # of processes executed
                continue;                               //move to next cycle
            }

            //if top execution status set to 1
            if (scheduleHeap.peek().isExecuting() == 1) {
                cout << "Process # " << scheduleHeap.peek().getPid() << " is executing.\n";
            }
        }
    }
    
    //print turnaround and wait time values
    cout << "The average turnaround is " << exeProcesses / atof(argv[2]) << " per cycle.\n";
    cout << "The average wait time is " << totWait / exeProcesses << ".\n";
    
    return 0;
}