#!/bin/bash

: <<"eof"
任务 计算程序执行时间
eof
begin=$(date +%s)
end=$(date +%s)
#run some long program
total_run=$(($end-$begin))