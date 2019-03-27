package main

import (
	"fmt"
	// "golang.org/x/tour/wc"
)


func MyWordCount(s string)map[string]int{
	for _,runeValue := range s{
		fmt.Printf("%#U\n",runeValue)
	}
	return map[string]int{"":1}
}

// func WordCount(s string) map[string]int {
// 	return map[string]int{"x": 1}
// }

func main() {
	// wc.Test(WordCount)
	s:="我是中国人我说中国话我写中国字中国是一个美丽富饶的国家"
	MyWordCount(s)
}
