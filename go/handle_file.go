package main

import (
	"fmt"
	"io/ioutil"
)

func main()  {
	filename := "data"
	f,err := ioutil.ReadFile(filename)
	if err != nil {
		fmt.Printf("worong!")
	}
	fmt.Printf("%s", f)
}