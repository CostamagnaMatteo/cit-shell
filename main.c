#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <errno.h>

#include "run_cmd.h"
#include "state.h"


#define debug printf





char* read_next_command(){
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us

  if (getline(&line, &bufsize, stdin) == -1){
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);  // We recieved an EOF
    } else  {
      perror("readline");
      exit(EXIT_FAILURE);
    }
  }
  line[strlen(line)-1] = '\0';

  return line;
}

/*
void run_builtin_cmd(char* cmd){
    if(strcmp(cmd_builtin_clear, cmd) == 0) {
      shift_terminal_down(50);
    }
}
*/


void free_state(struct cit_state* state_ptr){
    free(state_ptr->current_folder_ptr);
    free(state_ptr);
}

void print_terminal_line(struct cit_state* state_ptr){
  
  printf("%s@%s [%s]$ ", state_ptr->current_user_passwd->pw_name, state_ptr->host_name, state_ptr->current_folder_ptr);
}

char** split_cmd_line(char line[]){
  char** cmd = (char**) malloc(10 * sizeof(char*));

  char* strptr;

  char* nxt_tkn = strtok_r(line, " \t", &strptr);
  int i = 0;
  while (nxt_tkn != NULL )
  {
    printf("\t == %s == \n", nxt_tkn);
    nxt_tkn = strtok_r(NULL, " \t", &strptr);
    line[i] = nxt_tkn;
  }

  return cmd;
  
}

int main(int argc, char const *argv[])
{
    struct cit_state* state_ptr = init_state(); 
    print_terminal_line(state_ptr);
    char* cmd = read_next_command();

    while( strcmp(cmd_builtin_exit, cmd) != 0){
      char* params[] = {NULL};

      char** splitted_cmd = split_cmd_line(cmd);
      fork_cmd(splitted_cmd);
      cmd = read_next_command();
      print_terminal_line(state_ptr);
    }
    
    printf("Bye Bye\n");
    
    free_state(state_ptr);
    return 0;
}

