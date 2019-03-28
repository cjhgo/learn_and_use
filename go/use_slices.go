package main

// import "golang.org/x/tour/pic"
import "fmt"

// func Pic(dx, dy int) [][]uint8 {
// }
type KeyValue struct {
	Key   string
	Value string
}

type sliceKeyValue []KeyValue
func main() {
	// pic.Show(Pic)
	data :=[]int{1,2,3,4,5}
	mykv :=sliceKeyValue{KeyValue{"a","b"}, KeyValue{"c","d"}}
	for i := range data{
		fmt.Println(i)
	}
	for pos,ele :=range mykv{
		fmt.Println(pos,ele.Key,ele.Value)
	}
}
