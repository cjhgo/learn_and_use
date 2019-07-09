: <<"eof"
protoc -I ../../protos --cpp_out=. ../../protos/helloworld.proto
g++ -std=c++11 `pkg-config --cflags protobuf grpc`  -c -o helloworld.pb.o helloworld.pb.cc
protoc -I ../../protos --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ../../protos/helloworld.proto
g++ -std=c++11 `pkg-config --cflags protobuf grpc`  -c -o helloworld.grpc.pb.o helloworld.grpc.pb.cc
g++ -std=c++11 `pkg-config --cflags protobuf grpc`  -c -o greeter_client.o greeter_client.cc
g++ helloworld.pb.o helloworld.grpc.pb.o greeter_client.o -L/usr/local/lib `pkg-config --libs protobuf grpc++ grpc` \
-pthread -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -ldl -o greeter_client
g++ -std=c++11 `pkg-config --cflags protobuf grpc`  -c -o greeter_server.o greeter_server.cc
g++ helloworld.pb.o helloworld.grpc.pb.o greeter_server.o -L/usr/local/lib `pkg-config --libs protobuf grpc++ grpc` \
-pthread -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -ldl -o greeter_server
eof
protoc --cpp_out=. hello.proto 
protoc hello.proto  --grpc_out=. --plugin=protoc-gen-grpc="/usr/local/bin/grpc_cpp_plugin"
g++ -pthread -std=c++11 -I/usr/local/include -c -o hello.pb.o hello.pb.cc
g++ -pthread -std=c++11 -I/usr/local/include -c -o hello.grpc.pb.o hello.grpc.pb.cc

g++ -pthread -std=c++11 -I/usr/local/include -c -o client.o client.cc
# g++  hello.pb.o hello.grpc.pb.o client.o -L/usr/local/lib `pkg-config --libs protobuf grpc++ grpc` -pthread -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -ldl -o client
# g++  hello.pb.o hello.grpc.pb.o client.o -pthread -std=c++11 -I/usr/local/include -L/usr/local/lib -lprotobuf -lgrpc++ -lgrpc  -o client
g++  hello.pb.o hello.grpc.pb.o client.o \
-std=c++11 -L/usr/local/lib -lprotobuf -lgrpc++ -lgrpc -pthread -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -ldl \
-o client


g++ -pthread -std=c++11 -I/usr/local/include -c -o server.o server.cc


g++  hello.pb.o hello.grpc.pb.o server.o \
-std=c++11 -L/usr/local/lib -lprotobuf -lgrpc++ -lgrpc -pthread -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -ldl \
-o server