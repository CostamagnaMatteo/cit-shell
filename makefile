CC = gcc
CFLAGS = -Wall --pedantic

PROGRAM_NAME = cit

FOLDER_OBJ = obj/

FOLDER_LIBS = libs/
FOLDER_BUILT_IN = built_in/

MAIN_FILE 		= main.c
SOURCE_FILES 	= run_cmd.c state.c cmd_io.c
HEADER_FILES 	= run_cmd.h state.h cmd_io.h


all: 
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) $(MAIN_FILE) $(SOURCE_FILES) $(HEADER_FILES)


