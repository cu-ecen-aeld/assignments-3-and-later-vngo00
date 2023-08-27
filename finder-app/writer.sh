#! /bin/bash
set -e
set -u

if (($# != 2))
then
	echo "Invalid number of arguments"
	echo "Usage $0 writerfile writerstr"
	exit 1
fi

#create dir if not exists
mkdir -p $( dirname $1)

echo $2 > $1

