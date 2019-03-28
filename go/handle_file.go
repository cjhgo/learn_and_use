package main

import (
	"fmt"
	"io/ioutil"
	"os"
)

func main()  {
	filename := "data"
	f,err := ioutil.ReadFile(filename)
	if err != nil {
		fmt.Printf("worong!")
	}
	fmt.Printf("%s", f)
	ff,err := os.Create("./cjh")
	if err != nil{
		panic(err)
	}
	defer ff.Close()
	ff.WriteString("我是中国人")
	ff.Sync()
}