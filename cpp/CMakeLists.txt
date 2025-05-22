project(CppExample)

# 服务端
add_executable(GrpcServer grpc_server.cpp
    generated/route_guide.grpc.pb.cc
    generated/route_guide.grpc.pb.h
    generated/route_guide.pb.cc
    generated/route_guide.pb.h)

target_link_libraries(GrpcServer PRIVATE protobuf::libprotobuf gRPC::grpc++_reflection gRPC::grpc++ absl::base absl::strings)

# 客户端
add_executable(GrpcClient grpc_client.cpp
    generated/route_guide.grpc.pb.cc
    generated/route_guide.grpc.pb.h
    generated/route_guide.pb.cc
    generated/route_guide.pb.h)

target_link_libraries(GrpcClient PRIVATE protobuf::libprotobuf gRPC::grpc++_reflection gRPC::grpc++)
