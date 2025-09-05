#include "cmd_io.h"

void print_terminal_line(struct cit_state* state_ptr){
  
  printf("%s@%s [%s]$ ", state_ptr->current_user_passwd->pw_name, state_ptr->host_name, state_ptr->current_folder_ptr);
}

char** split_line_to_cmd(char line[]){
  char **cmd = (char**) malloc((MAX_CMD_ARGC + 1) * sizeof(char*));

  char *strptr;

  char *nxt_tkn = strtok_r(line, " \t", &strptr);
  int i = 0;
  while (nxt_tkn != NULL && i < MAX_CMD_ARGC)
  {
    cmd[i++] = nxt_tkn;
    nxt_tkn = strtok_r(NULL, " ", &strptr);
  }

  do{
    cmd[i++] = NULL;
  }while(i < MAX_CMD_ARGC + 1);
  


  return cmd;
  
}

char* read_line(){
  char *line = NULL;
  size_t bufsize = 0;

  if (getline(&line, &bufsize, stdin) == -1){
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);
    } else  {
      perror("readline");
      exit(EXIT_FAILURE);
    }
  }
  line[strlen(line)-1] = '\0';

  return line;
}