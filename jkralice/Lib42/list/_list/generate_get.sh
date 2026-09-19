#!/bin/bash

TYPE="$1"
LIST="$2"
NODE="$3"

cat <<EOF
#include "../${LIST}.h"
#include "../_list/_dllist.h"

t_${NODE}	*${LIST}_get(t_${LIST} *list, size_t idx)
{
	return (_dllist_get((t_dllist *)list, idx));
}
EOF
