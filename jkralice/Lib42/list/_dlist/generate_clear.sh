#!/bin/bash

TYPE="$1"
LIST_TYPE="$2"
LIST_PREFIX="$3"
NODE_TYPE="$4"
NODE_PREFIX="$5"

cat <<EOF
#include "../${LIST_PREFIX}.h"
#include "../_dlist/_dlist.h"

void	${LIST_PREFIX}_clear(${LIST_TYPE} *list)
{
	_dlist_clear(list);
}
EOF
