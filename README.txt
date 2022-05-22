Ans 1)
        Using fork()

        -In the main function we used the system call fork() to call the child and the parent process
        We initialised the fork function with an integer sect, that is because it will call the child process when its 0 
        and the parent process when it's something other than 0.
        I created two functions, one for calculating the average of the sections each.
         logic for both of them was the same.
        First the file was opened and initialised with an integer to check if it's openable or not.
        Then the file was being read character by character. Using "strtok" for every character encountered which was equal 
        to either sections the next six had to be the marks and were added to the total of the asignments respectively.
        With the marks a float variable also kept a track of the number of students in a section.
        In the end the average was calculated and printed on the terminal. 
        Waitpid function will wait for the child process to terminate and then execute the parent process.

        Using threads()

        -Here the system call pthreads were used in the main function and apart from the fork part one other function 
        was created to check the average of both the sections. 
        pthread_create was used to create a thread that was initialised earlier using pthread_t.
        Then pthread_join was used to suspend the execution of the calling thread. Then the other two functions were 
        called.

      
       
