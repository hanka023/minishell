#!/bin/bash

TYPE="$1"
LIST_TYPE="$2"
LIST_PREFIX="$3"
NODE_TYPE="$4"
NODE_PREFIX="$5"

cat <<EOF
#include "../${LIST_PREFIX}.h"
#include "../_dlist/_dlist.h"

${TYPE}	*${NODE_PREFIX}_data(${NODE_TYPE} *node)
{
	return (_dnode_data(node));
}

${NODE_TYPE}	*${NODE_PREFIX}_prev(${LIST_TYPE} *list, ${NODE_TYPE} *node)
{
	return (_dnode_prev(list, node));
}

${NODE_TYPE}	*${NODE_PREFIX}_next(${LIST_TYPE} *list, ${NODE_TYPE} *node)
{
	return (_dnode_next(list, node));
}
EOF
