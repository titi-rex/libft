# Sources directory
SRC_DIR	:= srcs
# Source list (empty at first)
SRC 	:=
# Include subdirectory sources.mk 
include ${SRC_DIR}/sources.mk

root_dir := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
# current := $(notdir $(patsubst %/,%,$(dir $(mk_file_path))))

ALL_SRC	:= $(subst $(root_dir), "", $(SRC))

OBJ_DIR	= .build
OBJ		= ${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${ALL_SRC}}

all: 
	@echo "${ALL_SRC}"
	@echo "${OBJ}"

