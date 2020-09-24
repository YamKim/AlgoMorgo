#!/usr/bin/zsh

echo -e -n "Which work directory?: "
read WORK_DIR

for DIR in $WORK_DIR/*;
do
	BASE_DIR="$(basename $DIR)"
	`cp /mnt/d/YamP/Algorithm/APSS/${BASE_DIR}/Algorithm.png $DIR`
	echo "success copy png in $BASE_DIR"
done
