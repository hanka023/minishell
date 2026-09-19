#!/bin/bash

TYPE="$1"
LIST="$2"
NODE="$3"

cat <<EOF
#include "../${LIST}.h"
#include "../_list/_dllist.h"

void	${LIST}_remove(t_${LIST} *list, size_t idx)
{
	_dllist_remove((t_dllist *)list, idx);
}

void	${LIST}_remove_back(t_${LIST} *list)
{
	_dllist_remove_back((t_dllist *)list);
}

void	${LIST}_remove_front(t_${LIST} *list)
{
	_dllist_remove_front((t_dllist *)list);
}

void	${LIST}_remove_node(t_${LIST} *list, t_${NODE} *node)
{
	_dllist_remove_node((t_dllist *)list, node);
}
EOF
