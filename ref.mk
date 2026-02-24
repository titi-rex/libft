
# root directory
# root_dir	:= $(dir $(abspath $(firstword $(MAKEFILE_LIST))))

# uniq = $(if $1,$(firstword $1) $(call uniq,$(filter-out $(firstword $1),$1)))

# Source directory
SRC_DIR		= srcs/
SRC_FILE = sources.mk
# Source list (empty at first)
# SRC	:=
# Include list
# INC	:=

# Include subdirectory sources.mk
# include ${SRC_DIR}sources.mk

-include $(SRC_FILE)

INC	+= include/libft

# All source files
ALL_SRC	= $(addsuffix .c, $(subst $(root_dir),, $(SRC)))
ALL_INC	= $(addsuffix .h, $(subst $(root_dir),, $(INC)))
ALL_OBJ	= ${patsubst ${SRC_DIR}%.c,${OBJ_DIR}%.o, $(ALL_SRC)}
SUBDIRS	= $(call uniq, $(dir $(ALL_OBJ)))

# CFlages
IFLAGS	= $(addprefix -I, $(dir $(ALL_INC)))

# directories
BUILD_DIR	= build/
OBJ_DIR		= ${BUILD_DIR}obj/
BIN_DIR		= ${BUILD_DIR}bin/


# General
all: ${ALL_OBJ}

clean:
	rm -rf ${OBJ_DIR}

fclean:
	rm -rf ${BUILD_DIR}

re: clean all

# Compilation
.SECONDEXPANSION:
${OBJ_DIR}%.o: ${SRC_DIR}%.c | $$(@D)
	@echo $$^
	cc $(IFLAGS) -c $< -o $@

dir_guard=@$(MKDIR_P) $(@D)

# Directory creation
$(SUBDIRS):
	mkdir -p $(SUBDIRS)

${BIN_DIR}:
	mkdir -p ${BIN_DIR}

PHONY: prep s
s:
	@echo $(SOURCES)


prep:
	@./tools/mk-src.sh $(SRC_DIR) $(SRC_FILE)

# Utils
e:
	@echo "${ALL_INC}"
	@echo "${ALL_SRC}"
	@echo "${ALL_OBJ}"
	@echo "$(call uniq, ${SUBDIRS})"
