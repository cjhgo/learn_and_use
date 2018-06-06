#!/bin/bash
array=( $@ )
len=${#array[@]}
EXTRA_ARGS=${array[@]:3:$len}
EXTRA_ARGS_SLUG=${EXTRA_ARGS// /"  --exclude "}
echo $EXTRA_ARGS_SLUG

syncd()
{
	array=( $@ )
	len=${#array[@]}
	EXTRA_ARGS=${array[@]:1:$len}
	excl_d=${EXTRA_ARGS// /"  --exclude "}
	echo "--exclude $EXTRA_ARGS_SLUG"
}
syncd /home/cjh/project/LazyGraph_all/LazyGraph/src output xls org
: '
exec &> >(tee -a "$LOG")
echo Logging output to "$LOG"
'