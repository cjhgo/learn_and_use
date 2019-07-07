#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "hello.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloReq;
using helloworld::HellResp;

class GreeterServiceImpl final : public Greeter::Service
{
  Status SayHi(ServerContext* context, const HelloReq* req, HellResp* reply) override
  {
    std::string prefix("Toda ");
    std::cout<< " aha i receive " << req->name()<<std::endl;
    reply->set_message(prefix+req->name()+"~~~");
    return Status::OK;
  }
};

void RunForever()
{
  std::string server_address("0.0.0.0:50055");
  GreeterServiceImpl service;
  ServerBuilder builder;

  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

  builder.RegisterService(&service);

  std::unique_ptr<Server> server(builder.BuildAndStart());

  std::cout << " Server listenging on " << server_address << std::endl;

  server->Wait();
}

int main(int argc, char** argv)
{
  RunForever();
}