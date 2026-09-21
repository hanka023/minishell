#!/bin/bash

TYPE="$1"
LIST="$2"
NODE="$3"

cat <<EOF
#include "../${LIST}.h"
#include "../_list/_dllist.h"

void	${LIST}_clear(t_${LIST} *list)
{
	_dllist_clear((t_dllist *)list);
}
EOF
