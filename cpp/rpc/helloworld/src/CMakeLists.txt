set(PROTOS
    ${CMAKE_CURRENT_SOURCE_DIR}/hello.proto
)

set(PROTO_SRC_DIR ${CMAKE_CURRENT_BINARY_DIR}/proto-src)
file(MAKE_DIRECTORY ${PROTO_SRC_DIR})
include_directories(${PROTO_SRC_DIR})

message("show" ${PROTOS})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SRC_DIR} ${PROTOS})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_SRC_DIR} ${PROTOS})


# Building server
add_executable(greeter_server
    ${CMAKE_CURRENT_SOURCE_DIR}/server.cc
    ${PROTO_SRCS}
    ${GRPC_SRCS}
)
target_link_libraries(greeter_server
    gRPC::grpc++_reflection
    protobuf::libprotobuf
)

# Building client
add_executable(greeter_client
    ${CMAKE_CURRENT_SOURCE_DIR}/client.cc
    ${PROTO_SRCS}
    ${GRPC_SRCS}
)
target_link_libraries(greeter_client
    gRPC::grpc++_reflection
    protobuf::libprotobuf
)
