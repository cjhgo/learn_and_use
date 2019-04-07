package main

import(
  "userpc"
  "log"
  "net"
  "net/http"
  "net/rpc"	
)

func main(){
  arith := new(userpc.Arith)
  err := rpc.Register(arith)
  if err != nil{
	log.Fatalf("register error:%s",err)
  }
  rpc.HandleHTTP()
  l,e := net.Listen("tcp", ":1234")
  if e != nil{
    log.Fatalf("listen error:%s",e)
  }
  log.Println("serving rpc handler")
  err = http.Serve(l,nil)
  if err != nil{
	log.Fatalf("serve error:%s", err)
  }
}
