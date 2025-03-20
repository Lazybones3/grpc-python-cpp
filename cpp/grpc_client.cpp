#include <grpcpp/grpcpp.h>
#include <iostream>
#include "generated/route_guide.grpc.pb.h"
#include "generated/route_guide.pb.h"

int main() {
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("127.0.0.1:50051", grpc::InsecureChannelCredentials());
    std::unique_ptr<routeguide::RouteGuide::Stub> stub = routeguide::RouteGuide::NewStub(channel);

    routeguide::RouteResponse response;
    grpc::ClientContext context;
    auto stream = stub->RouteChat(&context);
    for (int i = 0; i < 100; ++i) {
        routeguide::RouteRequest request;
        request.set_id(i+1);
        stream->Write(request);
        stream->Read(&response);
        std::cout << "Client received: " << response.message() << std::endl;
    }
    stream->WritesDone();
    return 0;
}
