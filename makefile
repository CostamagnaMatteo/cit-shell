CC = gcc
CFLAGS = 

PROGRAM_NAME = cit

FOLDER_OBJ = obj/

FOLDER_LIBS = libs/
FOLDER_BUILT_IN = built_in/

SOURCE_FILES = main.c run_cmd.c state.c
HEADER_FILES = run_cmd.h state.h


all: 
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) $(SOURCE_FILES) $(HEADER_FILES)


