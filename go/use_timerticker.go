package main

import "fmt"
import "time"


func main(){
	
	heart :=  150*time.Millisecond
	timer := time.NewTimer(heart)
	for{		
		select {
		case t:=<-timer.C:
			fmt.Printf("hhhh, %v %v\n",t,timer.Reset(heart))
			
		}

	}
	
}