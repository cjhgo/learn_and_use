package main

/**
 此文件用于演示golang中的字符编码的问题
*/
import "fmt"
import "unsafe"

func main()  {
  strchen :=`陈`
  runechen :='陈'
  fmt.Printf("%T %d %d\n", strchen,unsafe.Sizeof(strchen), len(strchen))
  fmt.Printf("%T %d\n", runechen,unsafe.Sizeof(runechen))
  fmt.Printf("%+q\n","\xbd\xb2\x3d\xbc\x20\xe2\x8c\x98") 

  fmt.Println("\n演示单引号,双引号,反引号常量\n")
  fmt.Printf("%T\n", 'x')//rune type ,int32
  fmt.Printf("%T\n", "X")//string type
  fmt.Printf("%T\n", `X`)//string type

  fmt.Println("\n演示按下标访问string,得到的是byte,也就是uint8\n")
  x:="x陈"
  fmt.Printf("%T\n", x[0])
  fmt.Printf("%T\n", x[1])

  fmt.Println("\n演示如何用Printf格式化字符,避免乱码\n")
  str := "xx陈我"
  fmt.Println(len(str)) //str是一个长度为8byte的slice
  fmt.Printf("% x\n", str)//以16进制输出str这个byte序列
  fmt.Printf("%q\n", str)//把能打印的打印出来
  fmt.Printf("%+q\n", str)//用\u格式来表示
  fmt.Printf("%#U\n", 38557)//把一个整数按U+值来解释,打印对应的字符
  

  for i := 0; i < len(str); i++{
    fmt.Printf("% x", str[i])
  }  
  fmt.Println("\n")
  for index, runeValue := range str{
    fmt.Printf("%d \t,16进制:%x \t 10进制:%d \t Unicode Value:%#U \t type: %T \t %x \t\n",index, runeValue,runeValue, runeValue, runeValue, str[index])
  }
}