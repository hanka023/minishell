#!/bin/bash

TYPE="$1"
LIST_TYPE="$2"
LIST_PREFIX="$3"
NODE_TYPE="$4"
NODE_PREFIX="$5"

cat <<EOF
#include "../${LIST_PREFIX}.h"
#include "../_dlist/_dlist.h"

${TYPE}	*${LIST_PREFIX}_get(${LIST_TYPE} *list, size_t idx)
{
	return (_dlist_get(list, idx));
}

${NODE_TYPE}	*${LIST_PREFIX}_get_node(${LIST_TYPE} *list, size_t idx)
{
	return (_dlist_add_back(list, idx));
}
EOF
