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
OBJ		= ${patsubst ${DIR_SRCS}%.c, ${OBJ_DIR}%.o, ${SRCS}}

all: 
	@echo "${root_dir}"
	@echo "${ALL_SRC}"

