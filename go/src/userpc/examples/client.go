package main

import(
  "userpc"
  "log"
  "net/rpc"
)

func main(){
  client,err := rpc.DialHTTP("tcp",":1234")
  if err != nil{
	log.Fatalf("dial error:%s",err)
  }
  args := &userpc.Args{7,8}
  var reply int
  err = client.Call("Arith.Multiply", args, &reply)
  if err != nil{
	log.Fatalf("rpc call error:%s", err)
  }
  log.Printf("the res of rpc call is:%d",reply)
}