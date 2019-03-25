package main

import "fmt"

func main()  {
  fmt.Println(len(`x#$@#$@#"""\xbd`)) 
  fmt.Println(len("\xbd\xb2\x3d\xbc\x20\xe2\x8c\x98")) 
  fmt.Printf("%+q\n","\xbd\xb2\x3d\xbc\x20\xe2\x8c\x98") 
  
  fmt.Println("!!!!\n")
  fmt.Println(len("xx")) 
  fmt.Println(len("你好")) 
  x:="x"

  fmt.Printf("%T\n", x[0])
  fmt.Printf("%T\n", 'x')
  fmt.Printf("%T\n", "X")
  fmt.Printf("%T\n", `X`)
  str := "xx我是整个人"
  fmt.Println(len(str)) 
  for i := len(str)-1; i >= 0; i--{
    fmt.Printf("% x", str[i])
  }  
  fmt.Println("\n")
  for index, runeValue := range str{
    fmt.Printf("%d \t, %x \t %T %x\n",index, runeValue, runeValue, str[index])
  }
}