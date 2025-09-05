#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef state_lib
#define state_lib
 
#define MAX_FOLDER_PATH_SIZE 1024
#define MAX_HOST_NAME_SIZE 256

extern const char default_folder_path[];
extern const char cmd_builtin_exit[];
extern const char cmd_builtin_clear[];

struct cit_state
{
    char* current_folder_ptr;

    char* host_name;

    uid_t current_user_id;
    struct passwd* current_user_passwd;

};

struct cit_state* init_state();

#endif