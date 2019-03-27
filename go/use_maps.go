package main

import (
	"fmt"
)


func MyWordCount(s string)map[string]int{
	//这只是声明
	//var res map[string]int
	//推荐这么用,声明并且初始化
	res :=make(map[string]int)
	for _,runeValue := range s{
		fmt.Printf("%#U\t%s\n",runeValue,string(runeValue))
		key:=string(runeValue)
		//用第二个返回值测试key是否存在
		_,ok:=res[key]
		if ok {
			res[key]++
		}else{
			res[key]=1
		}
	}
	return res
}

// func WordCount(s string) map[string]int {
// 	return map[string]int{"x": 1}
// }

func main() {
	s:="我是中国人我说中国话我写中国字中国是一个美丽富饶的国家"
	//用range遍历map
	for key,value := range MyWordCount(s){
		fmt.Println(key,value)
	}
}
