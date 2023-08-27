#! /bin/bash

if (($# != 2))
then
	echo "invalid number of arguments"
	echo "Usage $0 filesdir searchstr"
	exit 1
fi

if [ ! -d $1 ]
then
	echo "$1 not a directory"
	exit 1
fi

X=$(find $1 -type f | wc -l)
Y=$(grep -r $2 $1 | wc -l)

echo "The number of files are $X and the number of matching lines are $Y"

