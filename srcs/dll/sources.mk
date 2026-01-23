# Module sources
_src	:= doubly_linked_list


# Module path
_dir := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

# Append to all sources
SRC 	+= $(addsuffix .c, $(addprefix ${_dir}, ${_src}))

# Include submodule sources
include $(wildcard $(dir $(abspath $(lastword $(MAKEFILE_LIST))))*/sources.mk)
