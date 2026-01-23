# Module sources
_src	:= order


# Module path
_dir := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

# Append to all sources
SRC 	+= $(addprefix ${_dir}, ${_src})

# Include submodule sources
include $(wildcard $(dir $(abspath $(lastword $(MAKEFILE_LIST))))*/sources.mk)
