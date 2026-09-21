#!/bin/bash

TYPE="$1"
LIST="$2"
NODE="$3"

cat <<EOF
#include "../${LIST}.h"
#include "../_list/_dllist.h"

t_${LIST}	*${LIST}_create(t_arena *arena)
{
	return (_dllist_create(arena));
}
EOF
