#!/bin/bash

if [ "$#" -lt 5 ]; then
	cat <<EOF
Usage: $0 type list_type list_prefix node_type node_prefix [headers...]

Where:
	type 			: Data type of the list.
	list_type		: Typedef of the generated list.
	list_prefix		: Prefix of the generated list functions. (Also the file names and header protector!)
	node_type		: Typedef of the generated node.
	node_prefix		: Prefix of the generated node functions.
	[headers...]	: Optional header includes. (Paths are relative to /list/!)
EOF
	exit 1
fi

TYPE="$1"
LIST_TYPE="$2"
LIST_PREFIX="$3"
NODE_TYPE="$4"
NODE_PREFIX="$5"

shift 5

cd "$(dirname "$0")"

mkdir -p $LIST_PREFIX

HEADER_FILE=${LIST_PREFIX}.h
NODE_FILE=${LIST_PREFIX}/${NODE_PREFIX}.c
CREATE_FILE=${LIST_PREFIX}/${LIST_PREFIX}_create.c
ADD_FILE=${LIST_PREFIX}/${LIST_PREFIX}_add.c
GETTERS_FILE=${LIST_PREFIX}/${LIST_PREFIX}_getters.c
GET_FILE=${LIST_PREFIX}/${LIST_PREFIX}_get.c
REMOVE_FILE=${LIST_PREFIX}/${LIST_PREFIX}_remove.c
CLEAR_FILE=${LIST_PREFIX}/${LIST_PREFIX}_clear.c
COPY_FILE=${LIST_PREFIX}/${LIST_PREFIX}_copy.c

# Header:
cat ../format/42_header > $HEADER_FILE
./_dlist/generate_header.sh $TYPE $LIST_TYPE $LIST_PREFIX $NODE_TYPE $NODE_PREFIX $@ | ../format/pad.sh $TYPE $LIST_TYPE $NODE_TYPE size_t void >> $HEADER_FILE

# Node functions:
cat ../format/42_header > $NODE_FILE
./_dlist/generate_node.sh $TYPE $LIST_TYPE $LIST_PREFIX $NODE_TYPE $NODE_PREFIX >> $NODE_FILE

# Create function:
cat ../format/42_header > $CREATE_FILE
./_dlist/generate_create.sh $TYPE $LIST_TYPE $LIST_PREFIX $NODE_TYPE $NODE_PREFIX >> $CREATE_FILE

# Add functions:
cat ../format/42_header > $ADD_FILE
./_dlist/generate_add.sh $TYPE $LIST_TYPE $LIST_PREFIX $NODE_TYPE $NODE_PREFIX >> $ADD_FILE

# Getter functions:
cat ../format/42_header > $GETTERS_FILE
./_dlist/generate_getters.sh $TYPE $LIST_TYPE $LIST_PREFIX $NODE_TYPE $NODE_PREFIX >> $GETTERS_FILE

# Get functions:
cat ../format/42_header > $GET_FILE
./_dlist/generate_get.sh $TYPE $LIST_TYPE $LIST_PREFIX $NODE_TYPE $NODE_PREFIX >> $GET_FILE

# Get functions:
cat ../format/42_header > $REMOVE_FILE
./_dlist/generate_remove.sh $TYPE $LIST_TYPE $LIST_PREFIX $NODE_TYPE $NODE_PREFIX >> $REMOVE_FILE

# Clear function:
cat ../format/42_header > $CLEAR_FILE
./_dlist/generate_clear.sh $TYPE $LIST_TYPE $LIST_PREFIX $NODE_TYPE $NODE_PREFIX >> $CLEAR_FILE

# Copy function:
cat ../format/42_header > $COPY_FILE
./_dlist/generate_copy.sh $TYPE $LIST_TYPE $LIST_PREFIX $NODE_TYPE $NODE_PREFIX >> $COPY_FILE

cat <<EOF
Generated!

Header:
$HEADER_FILE

Sources:
$NODE_FILE
$CREATE_FILE
$ADD_FILE
$GETTERS_FILE
$GET_FILE
$REMOVE_FILE
$CLEAR_FILE
$COPY_FILE
EOF
