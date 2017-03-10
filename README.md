# CPUScheduler
Non-preemptive priority CPU scheduler simulation implemented using a heap for CSC 3102 Advanced Data Structures & Algorithm Analysis.  This program creates simulated CPU jobs with an associated priority value [-20,19] and length value [1,100].  The program uses a heap in order to ensure that the job with the highest priority is operated on first.  In the case that there exist two jobs with the same priority, the one created first will be operated on first.  The program accepts command line argumensts p, a value between 0.01 and 1, that is the probability that a new job is created during a given cycle and s, the number of time cycles the simulation will run.  The program then outputs the cycle number, if a process has been terminated, if a process is executing, and/or if a job has been created for each cycle of the simulation.
# Execution
Run makefile with all .cpp and .h files in the same directory.
# Project Instructions
The file csc3102proj01s17.pdf contains instructions for the project as specified by the instructor.
