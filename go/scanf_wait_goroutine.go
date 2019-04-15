package main

import "fmt"

func main() {
	go func(){
		fmt.Println("hello,world")
	}()	
	var i int
	fmt.Scanf("%d", &i)
}