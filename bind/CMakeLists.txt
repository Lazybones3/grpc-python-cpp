project(BindExample)

# pybind11
#set(Python_ROOT_DIR "path to python document directory")
find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)
message(STATUS "Using pybind11 ${pybind11_VERSION}")

# 客户端
pybind11_add_module(PyClientModule PyClientModule.cpp
    PyClient.cpp PyClient.h
    ../cpp/generated/route_guide.grpc.pb.cc
    ../cpp/generated/route_guide.grpc.pb.h
    ../cpp/generated/route_guide.pb.cc
    ../cpp/generated/route_guide.pb.h)

target_link_libraries(PyClientModule PRIVATE protobuf::libprotobuf gRPC::grpc++_reflection gRPC::grpc++ pybind11::module)
