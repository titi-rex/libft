#!/bin/env zsh
# This script update a file containing a list of the project sources files

echo_and_exit () {
    echo "$1"
    exit $2
}

set -e

# check parameter
src_dir=$1
[[ -z $src_dir ]] && echo_and_exit "Source directory not supplied" 1

src_file=$2
[[ -z $src_file ]] && echo_and_exit "Source file not supplied" 1

# get sources files presents in dir
news=$(find $src_dir -name "*.c")
# get sources files list declared in $src_file
old=$(cat $src_file | tr ' ' '\n' | tail -n +3)

# diff
diffs=$(diff --color=always <(echo $old) <(echo $news) | tail -n +2)

# if no diff, nothing to do, exit
[[ -z $diffs ]] && echo_and_exit "No changes" 0

# output changes
echo -e "Changes:\n${diffs}"

# create new src_file with the updated sources files list
echo -n "SRC = " > $src_file
echo $news | tr '\n' ' ' >> $src_file
