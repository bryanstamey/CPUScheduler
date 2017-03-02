/**
 * Describe a process control block
 * @author Duncan
 * @date 99-99-9999    
 */

#include <string>
#include <iostream>
    
using namespace std;


class PCB
{
private:
   /**
    * the process ID
	*/
   int pid;
   /**
    * the priority value of this process [-20,19]
	*/
   int priority;
   /**
    * the running status of this process
	* [0 = not running, 1 = running]
	*/
   int running;
   /**
    * the cycle during which this process was created
	*/
   int arrived;
   /**
    * the quantum (number of cycles required to execute)
	* this process
	*/
   int length;
   /**
    * the cycle when this process began running
	*/
   int start;
   /**
    * the number of cycles from the creation of this process
	* to when it began running
	*/
   int wait;	
public:
   /**
    * Create a a PCB with the lowest priority
	* and a quantum of 0 (default constructor)
    */
   PCB()
   {
      priority = 19;
      running = 0;
      arrived = 0;
      length = 0;
   }

   /**
    * Creates a PCB with the specified parameters.
    * @param id the process ID
    * @param pVal priority value [-20,19]
    * @param run executing status [0 = not running, 1 = running] 
    * @param arr the cycle during which the process arrived
    * @param len the quantum - number of cycles required to execute
    * the process
    */	
   PCB(int id, int pVal, int run, int arr, int len)
   {
      pid = id;
      priority = pVal;
      running = run;
      arrived = arr;
      length = len;
   }

   /**
    * Gives the ID for this process.
    * @return the pid of this process
    */    
   int getPid() const
   {
      return pid;
   }

   /**
    * Gives the priority value for this process.
    * @return the priority of this process
    */     
   int getPriority() const
   {
      return priority;
   }
  
   /**
    * Gives the running status of this process.
    * @return the running status of this process
    */    
   bool isExecuting() const
   {
      return (running == 1);
   }

   /**
    * Sets the running status of this process to 1.
    */     
   void execute()
   {
      running = 1;
   }

   /**
    * Gives the arrival time for this process.
    * @return cycle during with this process was created
    */     
   int getArrival() const
   {
      return arrived;
   }

   /**
    * Gives the quantum of this process.
    * @return the number of cycles required to execute this process
    */     
   int getLength() const
   {
      return length;
   }

   /**
    * Gives the cycle during which this process began running.
    * @return the cycle during which this process began running
    */     
   int getStart() const
   {
      return start;
   }

   /**
    * Sets the start cyle for this process.
    * @param startCycle the cycle during which this process began
	* running.
    */     
   void setStart(int startCycle)
   {
      start = startCycle;
   }

   /**
    * Gives the wait time for this process.
    * @return the number of cycles this process waited
	* before running.
    */     
   int getWait() const
   {
      return wait;
   }

   /**
    * Sets the wait time for this process.
    */     
   void setWait(int waitTime)
   {
      wait = waitTime;
   }

   /**
    * Overloaded == operator that determines whether
	* two process control blocks are the same.
	* @param pcb1 a process control block
	* @param pcb2 a process control block
	* @return true if the PCBs are the same; otherwise, false
	*/
   friend bool operator==(const PCB& pcb1, const PCB& pcb2);
   /**
    * Overloaded != operator that determines whether
	* two process control blocks are different.
	* @param pcb1 a process control block
	* @param pcb2 a process control block
	* @return true if the PCBs are different; otherwise, false
	*/   
   friend bool operator!=(const PCB& pcb1, const PCB& pcb2);
   /**
    * Overloaded > operator that determines whether
	* the first PCB has a higher priority than the second.
	* @param pcb1 a process control block
	* @param pcb2 a process control block
	* @return true if the first PCB has a higher priority than the second;
	* otherwise, false
	*/      
   friend bool operator>(const PCB& pcb1, const PCB& pcb2);
   /**
    * Overloaded < operator that determines whether
	* the first PCB has a lower priority than the second.
	* @param pcb1 a process control block
	* @param pcb2 a process control block
	* @return true if the first PCB has a lower priority than the second;
	* otherwise, false
	*/    
   friend bool operator<(const PCB& pcb1, const PCB& pcb2);
   /**
    * Overloaded >= operator that determines whether
	* the first PCB has the same or higher priority than the second.
	* @param pcb1 a process control block
	* @param pcb2 a process control block
	* @return true if the first PCB has the same or higher priority than 
	* the second; otherwise, false
	*/     
   friend bool operator>=(const PCB& pcb1, const PCB& pcb2);
   /**
    * Overloaded <= operator that determines whether
	* the first PCB has the same or lower priority than the second.
	* @param pcb1 a process control block
	* @param pcb2 a process control block
	* @return true if the first PCB has the same or lower priority than 
	* the second; otherwise, false
	*/    
   friend bool operator<=(const PCB& pcb1, const PCB& pcb2);
};

bool operator==(const PCB& pcb1, const PCB& pcb2)
{ 
   return (pcb1.running == pcb2.running &&
           pcb1.priority == pcb2.priority &&
           pcb1.arrived == pcb2.arrived);
}   

bool operator!=(const PCB& pcb1, const PCB& pcb2)
{   
   return (!(pcb1 == pcb2));
}   

bool operator>(const PCB& pcb1, const PCB& pcb2)
{   
   if (pcb1.running > pcb2.running)
      return true;
   if (pcb1.running < pcb2.running)
      return false;
   if (pcb1.priority < pcb2.priority)
      return true;
   if (pcb1.priority > pcb2.priority)
      return false;
   if (pcb1.arrived < pcb2.arrived)
      return true;
   else
      return false;
}   

bool operator<(const PCB& pcb1, const PCB& pcb2)
{   
   return ((pcb1 != pcb2) && !(pcb1 > pcb2));
}   

bool operator<=(const PCB& pcb1, const PCB& pcb2)
{   
   return (pcb1 > pcb2 || pcb1 == pcb2);
}   

bool operator>=(const PCB& pcb1, const PCB& pcb2)
{   
   return (pcb1 > pcb2 || pcb1 == pcb2);
}   

