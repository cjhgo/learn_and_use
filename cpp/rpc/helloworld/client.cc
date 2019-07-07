#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "hello.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloReq;
using helloworld::HellResp;


class GreeterClient{
public:
  GreeterClient(std::shared_ptr<Channel> channel)
  :stub_(Greeter::NewStub(channel)){};
  std::string SayHi(const std::string& user)
  {
    HelloReq req;
    req.set_name(user);
    HellResp reply;
    ClientContext context;
    Status status = stub_->SayHi(&context, req, &reply);
    if(status.ok())
    {
      return reply.message();
    }else
    {
      std::cout<< status.error_code() << ": " << status.error_message()
               << std::endl;
      return "Rpc failed";
    }
    
  }
private:
  std::unique_ptr<Greeter::Stub> stub_;
};

int main(int argc, char** argv)
{
  GreeterClient client(
      grpc::CreateChannel(
        "localhost:50055",grpc::InsecureChannelCredentials()
      )
  );

  std::string user("cjh");
  std::string reply = client.SayHi(user);
  std::cout<< "Client received " << reply << std::endl;
}