package main

import "fmt"
import "sync"

func main(){
	i := 0
	j := 5
	var mu sync.Mutex 
	for k:=0;k< 1000;k++{
		go func(){
			mu.Lock()			
			i += 1
			mu.Unlock()
		}()
	}	
	fmt.Scanf("%d",&j)
	fmt.Println(i)
}