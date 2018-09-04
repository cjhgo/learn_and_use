package main

import (
	"fmt"
)

type Vertex struct {
	X, Y float64
}

func (v Vertex) Abs(a float64) float64 {
	return a+v.X+v.Y
}

func main() 
{
	v := Vertex{3, 4}
	fmt.Println(v.Abs(5))
}
