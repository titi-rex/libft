# Module sources
_src	:= sort

# Module path
_dir := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

# Append to all sources
SRC 	+= $(addprefix ${_dir}, ${_src})

# Include submodule sources
include $(wildcard $(_dir)*/sources.mk)
