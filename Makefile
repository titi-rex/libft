# root directory
root_dir	:= $(dir $(abspath $(firstword $(MAKEFILE_LIST))))

# Source directory
SRC_DIR		= srcs/
# Source list (empty at first)
SRC :=

# Include subdirectory sources.mk 
include ${SRC_DIR}sources.mk

# All source files 
ALL_SRC = $(addsuffix .c, $(subst $(root_dir),, $(SRC)))
OBJ = ${patsubst ${SRC_DIR}%.c,${OBJ_DIR}%.o, $(ALL_SRC)}


# directories
BUILD_DIR	= build/
OBJ_DIR		= ${BUILD_DIR}obj/
BIN_DIR		= ${BUILD_DIR}bin/


# General
all: ${OBJ_DIR} ${OBJ}

clean:
	rm -rf ${OBJ_DIR}

fclean:
	rm -rf ${BUILD_DIR}

re: clean all


# Compilation 
${OBJ_DIR}%.o: ${SRC_DIR}%.c  
	cc -c $< -o $@


# Directory creation
${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${BIN_DIR}:
	mkdir -p ${BIN_DIR}

# Utils
e:
	@echo "${SRC_DIR}"
	@echo "${ALL_SRC}"
	@echo "${OBJ}"

