#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

void fork_cmd(char** cmd){
    pid_t pid, wpid;

    int status;
    
    pid = fork();

    printf("PID: %i\n", pid);
    if(pid < 0){
        //TODO: if the code run this block of code is because something bad appened while spwaning a new process
    } else if(pid == 0){
        
        int exec_result = execvp(cmd[0], ++cmd);
        printf("\n\nHo eseguito il comando richiesto -- %s %i &(%i)\n\n", cmd[0], exec_result, errno);
        exit(1);
    } else {
        do {
        wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        printf("ho terminato l'attesa del comando\n");
    }
}