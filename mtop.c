#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    /* Syscall invocation here */

    // calls int memtop();
    int available_mem = memtop();
    printf(1, "Available Memory: %d\n", available_mem);

    // run getmeminfo 
    int pid = fork();

    if (pid == 0){
        // child process
    }
    else {
        // parent, pid = new process
        wait();
        int len = 16;
        char name[len];
        for (int process = 1; process < pid; process++){
            int process_memory = getmeminfo(process, name, len);
            if (process_memory < 0){
                printf(1, "pid: %d, process not found.\n", process);
            }
            else {
                printf(1, "pid: %d, name: %s, mem: %d\n", process, name, process_memory);
            }
        }

    }
    exit();
}