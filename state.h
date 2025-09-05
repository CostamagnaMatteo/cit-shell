#include <pwd.h>

// The max number of chars 
#define MAX_FOLDER_PATH_SIZE 1024
#define MAX_HOST_NAME_SIZE 256
static const char default_folder_path[] = "/home/matteo/Desktop/";
static const char cmd_builtin_exit[] = "exit";
static const char cmd_builtin_clear[] = "clear";

struct cit_state
{
    char* current_folder_ptr;

    char* host_name;

    uid_t current_user_id;
    struct passwd* current_user_passwd;

};

struct cit_state* init_state();