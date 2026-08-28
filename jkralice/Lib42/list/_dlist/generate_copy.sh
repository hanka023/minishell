#!/bin/bash

TYPE="$1"
LIST_TYPE="$2"
LIST_PREFIX="$3"
NODE_TYPE="$4"
NODE_PREFIX="$5"

cat <<EOF
#include "../${LIST_PREFIX}.h"
#include "../_dlist/_dlist.h"

${LIST_TYPE}	*${LIST_PREFIX}_copy(t_arena *arena, ${LIST_TYPE} *list)
{
	return (_dlist_copy(arena, list, sizeof(${TYPE})));
}
EOF
