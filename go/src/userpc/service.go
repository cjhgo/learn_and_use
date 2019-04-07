package userpc

import "log"

type Arith int

type Args struct{
	A,B int
}
func (t *Arith) Multiply(args Args, reply *int)error{
	log.Println("call method multiply")
	*reply =args.A*args.B
	return nil
}