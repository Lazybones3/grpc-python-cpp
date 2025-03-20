cmake_minimum_required(VERSION 3.20)
project(GrpcCppExample)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_PREFIX_PATH ${THIRD_PARTY_DIR}/grpc)

find_package(absl CONFIG REQUIRED)
message(STATUS "Using absl ${absl_VERSION}")

# Protobuf
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")
# gRPC
find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")

# 服务端
add_executable(GrpcServer cpp/grpc_server.cpp
    cpp/generated/route_guide.grpc.pb.cc
    cpp/generated/route_guide.grpc.pb.h
    cpp/generated/route_guide.pb.cc
    cpp/generated/route_guide.pb.h)

target_link_libraries(GrpcServer PRIVATE protobuf::libprotobuf gRPC::grpc++_reflection gRPC::grpc++ absl::base absl::strings)

# 客户端
add_executable(GrpcClient cpp/grpc_client.cpp
    cpp/generated/route_guide.grpc.pb.cc
    cpp/generated/route_guide.grpc.pb.h
    cpp/generated/route_guide.pb.cc
    cpp/generated/route_guide.pb.h)

target_link_libraries(GrpcClient PRIVATE protobuf::libprotobuf gRPC::grpc++_reflection gRPC::grpc++)
