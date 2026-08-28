#!/bin/bash

TYPE="$1"
LIST_TYPE="$2"
LIST_PREFIX="$3"
NODE_TYPE="$4"
NODE_PREFIX="$5"

shift 5

HEADER_PROT=$(echo "$LIST_PREFIX" | tr '[:lower:]' '[:upper:]')

INCLUDE_BLOCK=""

for header in "$@"
do
	INCLUDE_BLOCK="${INCLUDE_BLOCK}# include \"${header}\"
"
done

if [ -n "$INCLUDE_BLOCK" ]; then
	INCLUDE_BLOCK="${INCLUDE_BLOCK}
"
fi

cat <<EOF
#ifndef ${HEADER_PROT}_H
# define ${HEADER_PROT}_H

# include "../arena.h"

${INCLUDE_BLOCK}typedef struct s_dlist	${LIST_TYPE};
typedef struct s_dnode	${NODE_TYPE};

${TYPE}			*${NODE_PREFIX}_data(${NODE_TYPE} *node);
${NODE_TYPE}	*${NODE_PREFIX}_next(${LIST_TYPE} *list, ${NODE_TYPE} *node);
${NODE_TYPE}	*${NODE_PREFIX}_prev(${LIST_TYPE} *list, ${NODE_TYPE} *node);

${LIST_TYPE}	*${LIST_PREFIX}_create(t_arena *arena);

${TYPE}			*${LIST_PREFIX}_add(${LIST_TYPE} *list, size_t idx);
${TYPE}			*${LIST_PREFIX}_add_back(${LIST_TYPE} *list);
${TYPE}			*${LIST_PREFIX}_add_front(${LIST_TYPE} *list);
${TYPE}			*${LIST_PREFIX}_add_before(${LIST_TYPE} *list, ${NODE_TYPE} *node);
${TYPE}			*${LIST_PREFIX}_add_after(${LIST_TYPE} *list, ${NODE_TYPE} *node);

${NODE_TYPE}	*${LIST_PREFIX}_start(${LIST_TYPE} *list);
${NODE_TYPE}	*${LIST_PREFIX}_end(${LIST_TYPE} *list);
size_t			${LIST_PREFIX}_size(${LIST_TYPE} *list);

${TYPE}			*${LIST_PREFIX}_get(${LIST_TYPE} *list, size_t idx);
${NODE_TYPE}	*${LIST_PREFIX}_get_node(${LIST_TYPE} *list, size_t idx);

void			${LIST_PREFIX}_remove(${LIST_TYPE} *list, size_t idx);
void			${LIST_PREFIX}_remove_back(${LIST_TYPE} *list);
void			${LIST_PREFIX}_remove_front(${LIST_TYPE} *list);
void			${LIST_PREFIX}_remove_node(${LIST_TYPE} *list, ${NODE_TYPE} *node);

void			${LIST_PREFIX}_clear(${LIST_TYPE} *list);

${LIST_TYPE}	*${LIST_PREFIX}_copy(t_arena *arena, ${LIST_TYPE} *list);

#endif
EOF
