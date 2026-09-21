#!/bin/bash

TYPE="$1"
LIST="$2"
NODE="$3"

cat <<EOF
#include "../${LIST}.h"
#include "../_list/_dllist.h"

t_${NODE}	*${NODE}_prev(t_${NODE} *node)
{
	return (_dllnode_prev(node));
}

t_${NODE}	*${NODE}_next(t_${NODE} *node)
{
	return (_dllnode_next(node));
}
EOF
