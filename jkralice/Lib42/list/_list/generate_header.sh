#!/bin/bash

TYPE="$1"
LIST="$2"
NODE="$3"

shift 3

HEADER_PROT=$(echo "$LIST" | tr '[:lower:]' '[:upper:]')

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
# include "_list/_dllist.h"

${INCLUDE_BLOCK}typedef const struct s_dllist \\
	t_${LIST};

typedef ${TYPE} \\
	t_${NODE};

t_${NODE}		*${NODE}_next(t_${NODE} *node);
t_${NODE}		*${NODE}_prev(t_${NODE} *node);

t_${LIST}		*${LIST}_create(t_arena *arena);

t_${NODE}		*${LIST}_add(t_${LIST} *list, size_t idx);
t_${NODE}		*${LIST}_add_back(t_${LIST} *list);
t_${NODE}		*${LIST}_add_front(t_${LIST} *list);
t_${NODE}		*${LIST}_add_before(t_${LIST} *list, t_${NODE} *node);
t_${NODE}		*${LIST}_add_after(t_${LIST} *list, t_${NODE} *node);

t_${NODE}		*${LIST}_get(t_${LIST} *list, size_t idx);

void			${LIST}_remove(t_${LIST} *list, size_t idx);
void			${LIST}_remove_back(t_${LIST} *list);
void			${LIST}_remove_front(t_${LIST} *list);
void			${LIST}_remove_node(t_${LIST} *list, t_${NODE} *node);

void			${LIST}_clear(t_${LIST} *list);

t_${LIST}		*${LIST}_copy(t_arena *arena, t_${LIST} *list);

#endif
EOF
