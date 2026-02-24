uniq = $(if $1,$(firstword $1) $(call uniq,$(filter-out $(firstword $1),$1)))

# Source directory
SRC_DIR		= srcs/
SRC_FILE = sources.mk


-include $(SRC_FILE)

INC	= include/libft

OBJ	= ${patsubst ${SRC_DIR}%.c,${OBJ_DIR}%.o, $(SRC)}
SUBDIRS	= $(call uniq, $(dir $(OBJ)))

# CFlages
IFLAGS	= $(addprefix -I, $(dir $(INC)))

# directories
BUILD_DIR	= build/
OBJ_DIR		= ${BUILD_DIR}obj/
BIN_DIR		= ${BUILD_DIR}bin/


# General
all: ${OBJ}

clean:
	rm -rf ${OBJ_DIR}

fclean:
	rm -rf ${BUILD_DIR}

re: clean all

# Compilation
${OBJ_DIR}%.o: ${SRC_DIR}%.c $(SUBDIRS)
	$(CC) $(IFLAGS) -c $< -o $@


# Directory creation
$(SUBDIRS):
	mkdir -p $(SUBDIRS)

${BIN_DIR}:
	mkdir -p ${BIN_DIR}

PHONY: prep
prep:
	@./tools/mk-src.sh $(SRC_DIR) $(SRC_FILE)

# Utils
e:
	@echo "${INC}"
	@echo "${SRC}"
	@echo "${OBJ}"
	@echo "$(call uniq, ${SUBDIRS})"
