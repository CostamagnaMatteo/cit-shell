#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <errno.h>

#include "run_cmd.h"
#include "state.h"
#include "cmd_io.h"

void free_state(struct cit_state* state_ptr){
    free(state_ptr->current_folder_ptr);
    free(state_ptr);
}


int main(int argc, char const *argv[])
{
    struct cit_state* state_ptr = init_state(); 
    print_terminal_line(state_ptr);
    char* cmd = read_line();

    while( strcmp(cmd_builtin_exit, cmd) != 0) {
      char** splitted_cmd = split_line_to_cmd(cmd);
      fork_cmd(splitted_cmd);
      cmd = read_line();
      print_terminal_line(state_ptr);
    }
    
    printf("Bye Bye\n");
    
    free_state(state_ptr);
    return 0;
}

