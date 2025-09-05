#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

void fork_cmd(char** cmd){
    pid_t pid;

    int status;
    
    pid = fork();

    if(pid < 0){
        //TODO: if the code run this block of code is because something bad appened while spwaning a new process
    } else if(pid == 0){
        execvp(cmd[0], cmd);
        exit(1);
    } else {
        do {
        waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}