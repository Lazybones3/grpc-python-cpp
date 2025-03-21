#### Python命令

- 安装grpc

```
pip install grpcio grpcio-tools
```

- 生成grpc代码

```shell
python -m grpc_tools.protoc -I ./protos --python_out=./python --grpc_python_out=./python ./protos/route_guide.proto
```

#### C++命令

```shell
# generate service codes
protoc -I ./protos --grpc_out=./cpp/generated --plugin=protoc-gen-grpc=F:/third_party/grpc/bin/grpc_cpp_plugin.exe ./protos/route_guide.proto
# generate message codes
protoc -I ./protos --cpp_out=./cpp/generated ./protos/route_guide.proto
```