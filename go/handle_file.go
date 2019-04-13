package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"bufio"
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
	ff,err = os.Create("./abc")
	defer ff.Close()
	w := bufio.NewWriter(ff)
	line := fmt.Sprintf("%d\n",333)
	w.WriteString(line)
	w.WriteString("方尽快为")
	w.Flush()
}