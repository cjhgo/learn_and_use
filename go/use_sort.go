package main

import "fmt"
import "sort"

type People struct{
	name string
	age int
}



func main(){
	people := []People{
		{"zhao", 18},
		{"qian", 12},
		{"sun", 33},
		{"li", 20},
	}

	sort.Slice(people, func(i,j int)bool{
		return people[i].age > people[j].age
	})
	fmt.Println(people)
}