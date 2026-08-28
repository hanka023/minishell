#!/bin/bash

TYPE="$1"
LIST_TYPE="$2"
LIST_PREFIX="$3"
NODE_TYPE="$4"
NODE_PREFIX="$5"

cat <<EOF
#include "../${LIST_PREFIX}.h"
#include "../_dlist/_dlist.h"

${NODE_TYPE}	*${LIST_PREFIX}_start(${LIST_TYPE} *list)
{
	return (_dlist_start(list));
}

${NODE_TYPE}	*${LIST_PREFIX}_end(${LIST_TYPE} *list)
{
	return (_dlist_end(list));
}

size_t	${LIST_PREFIX}_size(${LIST_TYPE} *list)
{
	return (_dlist_size(list));
}
EOF
