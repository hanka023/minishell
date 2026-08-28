#!/bin/bash

[ $# -ge 1 ] || {
	echo "Usage: $0 STRING..." >&2
	exit 1
}

awk -v words="$*" '
BEGIN {
	TAB = 4

	n = split(words, w, " ")

	max = 0
	for (i = 1; i <= n; i++)
		if (length(w[i]) > max)
			max = length(w[i])

	target = int(max / TAB + 1) * TAB
}

{
	for (i = 1; i <= n; i++) {
		if ($0 ~ "^" w[i] "[[:space:]]") {
			rest = substr($0, length(w[i]) + 1)
			sub(/^[[:space:]]+/, "", rest)

			tabs = (target - length(w[i])) / TAB

			printf "%s", w[i]
			while (tabs-- > 0)
				printf "\t"
			print rest

			next
		}
	}

	print
}
'
