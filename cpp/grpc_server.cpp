#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/health_check_service_interface.h>
#include <iostream>
#include "absl/strings/str_format.h"
#include "generated/route_guide.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerReaderWriter;

class RouteGuideImpl final : public routeguide::RouteGuide::Service {
public:
    Status RouteChat(ServerContext *context, ServerReaderWriter<routeguide::RouteResponse, routeguide::RouteRequest> *stream) override {
        routeguide::RouteRequest request;
        while (stream->Read(&request)) {
            std::unique_lock<std::mutex> lock(mu_);
            std::cout << "Server Received: " << request.id() << std::endl;
            routeguide::RouteResponse response;
            response.set_message("hello " + std::to_string(request.id()));
            stream->Write(response);
        }
        return Status::OK;
    }
private:
    std::mutex mu_;
};

int main() {
    int port = 50051;
    std::string server_address = absl::StrFormat("0.0.0.0:%d", port);

    RouteGuideImpl route_guide_impl;
//    grpc::EnableDefaultHealthCheckService(true);
//    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&route_guide_impl);
    // Finally assemble the server.
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
    return 0;
}
