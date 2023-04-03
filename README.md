1. Authors: Andrew Nguyen, Harry Nguyen.
+ We worked together to finish this project and took turns to pushed the changes to the master branch.
2. Features include mounting priority queues onto the process list using the ML algorithm and a renice function that allows user to change the priority of an individual process.
+ Applied the ML Algorithm by using 5 priority queues for the processes (processes in higher queue will run before other process of lower queues). Highest is queue5 and lowest is queue1. Default for new processes is queue3.
+ Edited the Scheduling by implementing the 5 queues in scheduling functions like enqueue (put a process in a specified queue), dequeue (remove a process from a specified queue), select (choose a process to run next based on the priority).
+ Created a ProcessOperation of RenicePID in the ProcessCtrl.h to serve the renice function which changes a process's priority.
+ Used the format of wait and waitpid to make renice and renicepid (renicepid is implemented as a supervisor call to access Kernel operation).
3. Screencast video link: https://youtu.be/NvH7bVQyUu8
