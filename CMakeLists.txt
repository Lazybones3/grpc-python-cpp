cmake_minimum_required(VERSION 3.20)
project(GrpcPythonCpp)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_PREFIX_PATH ${THIRD_PARTY_DIR}/grpc ${THIRD_PARTY_DIR}/pybind11)

find_package(absl CONFIG REQUIRED)
message(STATUS "Using absl ${absl_VERSION}")

# Protobuf
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")
# gRPC
find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")

add_subdirectory(cpp)
add_subdirectory(bind)
