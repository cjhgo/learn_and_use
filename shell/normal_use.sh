#!/bin/bash

: <<"eof"
任务 计算程序执行时间
用date +%s
脚本中有一个预定义的变量
记录了脚本从执行到目前为止,用的时间
eof
begin=$(date +%s)
#echo $SECONDS
echo $SECONDS
sleep 5;
#run some long program
end=$(date +%s)
total_run=$(($end-$begin))

echo $total_run
sleep 10;
echo $SECONDS