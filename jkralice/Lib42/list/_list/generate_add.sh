#!/bin/bash

TYPE="$1"
LIST="$2"
NODE="$3"

cat <<EOF
#include "../${LIST}.h"
#include "../_list/_dllist.h"

t_${NODE}	*${LIST}_add(t_${LIST} *list, size_t idx)
{
	return (_dllist_add((t_dllist *)list, idx, sizeof(${TYPE})));
}

t_${NODE}	*${LIST}_add_back(t_${LIST} *list)
{
	return (_dllist_add_back((t_dllist *)list, sizeof(${TYPE})));
}

t_${NODE}	*${LIST}_add_front(t_${LIST} *list)
{
	return (_dllist_add_front((t_dllist *)list, sizeof(${TYPE})));
}

t_${NODE}	*${LIST}_add_before(t_${LIST} *list, t_${NODE} *node)
{
	return (_dllist_add_before((t_dllist *)list, node, sizeof(${TYPE})));
}

t_${NODE}	*${LIST}_add_after(t_${LIST} *list, t_${NODE} *node)
{
	return (_dllist_add_after((t_dllist *)list, node, sizeof(${TYPE})));
}
EOF
