package main

import "fmt"
func main(){
	ch := make(chan int)
	numbers := []int{3,4,67,8,9}
	for _,i := range numbers{
		x := i
		go func(){
			fmt.Println("print in routine",x)
			//如果直接使用i,那么最后写到channel中的都会是9
			ch <- i
		}()
	}
	for i := 0; i < len(numbers); i++{
		fmt.Println("receive:",<-ch)
	}	
}