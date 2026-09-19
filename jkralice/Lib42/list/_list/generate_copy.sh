#!/bin/bash

TYPE="$1"
LIST="$2"
NODE="$3"

cat <<EOF
#include "../${LIST}.h"
#include "../_list/_dllist.h"

t_${LIST}	*${LIST}_copy(t_arena *arena, t_${LIST} *list)
{
	return (_dllist_copy(arena, (t_dllist *)list, sizeof(${TYPE})));
}
EOF
