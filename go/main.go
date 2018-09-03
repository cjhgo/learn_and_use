package main
import (
	"fmt"
	"time"
	"math"
	"math/rand"
)
func minus(x ,y int) int{
	return y-x
}
func swap(stra,strb string) (string,string){
	return strb,stra
}
func main()  {
	
	fmt.Println("hello,world")
	fmt.Println("the time is", time.Now())
	fmt.Println("gen number", rand.Intn(100))
	fmt.Println("the pi is", math.Pi)
	fmt.Println("18 -12 is", minus(12,18))
	fmt.Println(swap("abc","def"))
	var a =  3
	c:=3
	b:=float64(a)
	fmt.Println(b,c)
	v := 42.3 // change me!
	defer fmt.Println(" i run latter")
	fmt.Printf("v is of type %T\n", v)
	sum := 0.0
	for i := 0; i < 10; i++{
		sum += float64(i)
	}
	fmt.Println("the res is", sum)	
	fmt.Println("in the end")
	for i := 0; i < 10; i++ {
		defer fmt.Println(i)
	}

}

