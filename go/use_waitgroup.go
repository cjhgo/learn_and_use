package main

import "fmt"
import "sync"
func main(){
	numbers := []int{3,4,67,8,9}
	var wg sync.WaitGroup
	for _,i := range numbers{		
		wg.Add(1)
		go func(x int){			
			// wg.Add(1) can not write here
			fmt.Println("print in routine2",x)
			wg.Done()
		}(i)
	}	
	wg.Wait()
	fmt.Println("///")
}