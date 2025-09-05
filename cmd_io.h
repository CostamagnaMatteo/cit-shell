#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
#include "state.h"
#include "string.h"

#ifndef cmd_io_lib
#define cmd_io_lib

#define CMD_MAX_LENGTH 255

char* read_line();
char** split_line_to_cmd(char line[]);
void print_terminal_line(struct cit_state* state_ptr);

#endif