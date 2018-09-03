package main

import "fmt"

// fibonacci is a function that returns
// a function that returns an int.
func fibonacci() func() int {
	index := 0
	item1 := 0
	item2 := 1
	return func () int{
		if index == 0{
			index++
			return 0
		}
		if index == 1{
			index++
			return 1
		}
		temp := item1 + item2
		item1 = item2
		item2 = temp
		return temp
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
