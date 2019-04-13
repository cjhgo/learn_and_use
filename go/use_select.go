package main

import "time"
import "fmt"

func main(){

	ch := make(chan string)
	go func(){
		ch <- "hhh"
	}()
	timerHeart := time.NewTimer(100 * time.Millisecond)
	select {
		case t := <- timerHeart.C:
			fmt.Println(t)
		case m := <- ch:
			fmt.Println(m)
			break
			fmt.Println("xxx")
	}
}