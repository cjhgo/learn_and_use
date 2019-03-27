package main

/**
 此文件用于演示golang中的字符编码的问题
*/
import "fmt"
import "unsafe"
import u "unicode/utf8" 

func main()  {
  strchen :=`陈`
  strchen2 :=`陈陈陈陈`
  runechen :='陈'
  fmt.Println("\n演示sizeof string得到的是slice header的size")
  fmt.Printf("%T %d %d\n", strchen,unsafe.Sizeof(strchen), len(strchen))
  fmt.Printf("%T %d %d\n", strchen2,unsafe.Sizeof(strchen2), len(strchen2))
  fmt.Println("\n演示rune的size,len")
  fmt.Printf("%T %d %d\n", runechen,unsafe.Sizeof(runechen), u.RuneLen(runechen))
  fmt.Printf("%+q\n","\xbd\xb2\x3d\xbc\x20\xe2\x8c\x98") 

  fmt.Println("\n演示单引号,双引号,反引号常量\n")
  fmt.Printf("%T\n", 'x')//rune type ,int32
  fmt.Printf("%T\n", "X")//string type
  fmt.Printf("%T\n", `X`)//string type

  fmt.Println("\n演示按下标访问string,得到的是byte,也就是uint8\n")
  x:="x陈"
  fmt.Printf("%T\n", x[0])
  fmt.Printf("%T\n", x[1])

  fmt.Println("\n演示手动创建[]byte,然后转换为string,\n")
  //string([]byte{0})得到的并不是"0"
  //string([]byte{48})得到的才是"0"
  mystr := []byte{0,0,1,2,48,48,233,153,136}
  fmt.Printf("%q\n",string(mystr))
  fmt.Printf("%+q\n",string(mystr))
  fmt.Printf("%+q\n",string([]byte{48}))
  fmt.Printf("%+q\n",string([]byte{0}))


  fmt.Println("\n演示如何用Printf格式化字符,避免乱码\n")
  str := "xx陈我"
  fmt.Println(len(str)) //str是一个长度为8byte的slice
  fmt.Printf("% x\n", str)//以16进制输出str这个byte序列
  fmt.Printf("%q\n", str)//把能打印的打印出来
  fmt.Printf("%+q\n", str)//用\u格式来表示
  fmt.Printf("%#U\n", 38557)//把一个整数按U+值来解释,打印对应的字符
  

  for i := 0; i < len(str); i++{
    fmt.Printf("% x %d ", str[i], str[i])
  }  
  fmt.Println("\n")
  //rune可以直接string(runevalue)
  for index, runeValue := range str{
    fmt.Printf("%d \t,16进制:%x \t 10进制:%d \t Unicode Value:%#U \t type: %T \t %s \t %x\n",
    index, runeValue,runeValue, runeValue, runeValue, string(runeValue),str[index])
  }
}