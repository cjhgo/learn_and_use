package main

import "time"
import "fmt"
import "math/rand"


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

	go func(){
		for{
			ch <- "jjjj"
			x := rand.Intn(15)+90
			fmt.Println("rand: ",x)
			time.Sleep(time.Duration(x) * time.Millisecond)
		}
	}()
	for{
		select {
		case <- ch://空语句的话,则发生此事件什么都不干
		case <- time.After(100*time.Millisecond):
			fmt.Println("wowow")			
		}
	}
}