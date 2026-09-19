#!/bin/bash

if [ "$#" -lt 3 ]; then
	cat <<EOF
Usage: $0 type list node [headers...]

Where:
	type 			: Data type of the list.
	list			: Name of the generated list.
	node			: Name of the generated node.
	[headers...]	: Optional header includes. (Paths are relative to list/.!)
EOF
	exit 1
fi

TYPE="$1"
LIST="$2"
NODE="$3"

shift 3

cd "$(dirname "$0")"

mkdir -p $LIST

HEADER_FILE=${LIST}.h
NODE_FILE=${LIST}/${NODE}.c
CREATE_FILE=${LIST}/${LIST}_create.c
ADD_FILE=${LIST}/${LIST}_add.c
GET_FILE=${LIST}/${LIST}_get.c
REMOVE_FILE=${LIST}/${LIST}_remove.c
CLEAR_FILE=${LIST}/${LIST}_clear.c
COPY_FILE=${LIST}/${LIST}_copy.c

# Header:
cat ../format/42_header > $HEADER_FILE
./_list/generate_header.sh $TYPE $LIST $NODE $@ | ../format/pad.sh $TYPE t_${LIST} $NODE t_${NODE} size_t void >> $HEADER_FILE

# Node functions:
cat ../format/42_header > $NODE_FILE
./_list/generate_node.sh $TYPE $LIST $NODE >> $NODE_FILE

# Create function:
cat ../format/42_header > $CREATE_FILE
./_list/generate_create.sh $TYPE $LIST $NODE >> $CREATE_FILE

# Add functions:
cat ../format/42_header > $ADD_FILE
./_list/generate_add.sh $TYPE $LIST $NODE >> $ADD_FILE

# Get functions:
cat ../format/42_header > $GET_FILE
./_list/generate_get.sh $TYPE $LIST $NODE >> $GET_FILE

# Remove functions:
cat ../format/42_header > $REMOVE_FILE
./_list/generate_remove.sh $TYPE $LIST $NODE >> $REMOVE_FILE

# Clear function:
cat ../format/42_header > $CLEAR_FILE
./_list/generate_clear.sh $TYPE $LIST $NODE >> $CLEAR_FILE

# Copy function:
cat ../format/42_header > $COPY_FILE
./_list/generate_copy.sh $TYPE $LIST $NODE >> $COPY_FILE

cat <<EOF
Generated!

Header:
$HEADER_FILE

Sources:
$NODE_FILE
$CREATE_FILE
$ADD_FILE
$GET_FILE
$REMOVE_FILE
$CLEAR_FILE
$COPY_FILE
EOF
