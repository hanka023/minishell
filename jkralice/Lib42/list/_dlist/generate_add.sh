#!/bin/bash

TYPE="$1"
LIST_TYPE="$2"
LIST_PREFIX="$3"
NODE_TYPE="$4"
NODE_PREFIX="$5"

cat <<EOF
#include "../${LIST_PREFIX}.h"
#include "../_dlist/_dlist.h"

${TYPE}	*${LIST_PREFIX}_add(${LIST_TYPE} *list, size_t idx)
{
	return (_dlist_add(list, idx, sizeof(${TYPE})));
}

${TYPE}	*${LIST_PREFIX}_add_back(${LIST_TYPE} *list)
{
	return (_dlist_add_back(list, sizeof(${TYPE})));
}

${TYPE}	*${LIST_PREFIX}_add_front(${LIST_TYPE} *list)
{
	return (_dlist_add_front(list, sizeof(${TYPE})));
}

${TYPE}	*${LIST_PREFIX}_add_before(${LIST_TYPE} *list, ${NODE_TYPE} *node)
{
	return (_dlist_add_before(list, node, sizeof(${TYPE})));
}

${TYPE}	*${LIST_PREFIX}_add_after(${LIST_TYPE} *list, ${NODE_TYPE} *node)
{
	return (_dlist_add_after(list, node, sizeof(${TYPE})));
}
EOF
