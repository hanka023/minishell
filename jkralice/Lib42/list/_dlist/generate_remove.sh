#!/bin/bash

TYPE="$1"
LIST_TYPE="$2"
LIST_PREFIX="$3"
NODE_TYPE="$4"
NODE_PREFIX="$5"

cat <<EOF
#include "../${LIST_PREFIX}.h"
#include "../_dlist/_dlist.h"

void	${LIST_PREFIX}_remove(${LIST_TYPE} *list, size_t idx)
{
	_dlist_remove(list, idx);
}

void	${LIST_PREFIX}_remove_back(${LIST_TYPE} *list)
{
	_dlist_remove_back(list);
}

void	${LIST_PREFIX}_remove_front(${LIST_TYPE} *list)
{
	_dlist_remove_front(list);
}

void	${LIST_PREFIX}_remove_node(${LIST_TYPE} *list, ${NODE_TYPE} *node)
{
	_dlist_remove_node(list, node);
}
EOF
