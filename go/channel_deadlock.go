package main
import "fmt"
import _ "sync"

func main(){
	message := make(chan string)
	// _ = message
	// var wg sync.WaitGroup
	// go func(){
	// 	wg.Add(1)
	// 	fmt.Println("fun 1")		
	// 	message <- "a"
	// 	wg.Done()
	// 	}()
	// go func(){
	// 	wg.Add(1)
	// 	fmt.Println("fun 2")		
	// 	message <- "b"
	// 	wg.Done()
	// 	}()
	fmt.Println("fun 3")
	// wg.Wait()
	go func(){message <- "c"}()
	message <- "d"
	fmt.Println("fun 4")
}