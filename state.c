#include <sys/types.h>

#include "state.h"

const char default_folder_path[] = "/home/matteo/Desktop/";
const char cmd_builtin_exit[] = "exit";
const char cmd_builtin_clear[] = "clear";

struct cit_state* init_state(){
    struct cit_state* state_ptr = (struct cit_state *) malloc(sizeof(struct cit_state));
    state_ptr->current_folder_ptr = (char *)malloc( MAX_FOLDER_PATH_SIZE * sizeof(char));
    strcpy(state_ptr->current_folder_ptr, default_folder_path);

    state_ptr->current_user_passwd = getpwuid(getuid());

    state_ptr->host_name = (char *)malloc( MAX_HOST_NAME_SIZE * sizeof(char));

    gethostname(state_ptr->host_name, MAX_HOST_NAME_SIZE);

    return state_ptr;
}