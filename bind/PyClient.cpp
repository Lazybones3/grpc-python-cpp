#include "PyClient.h"

PyClient::PyClient(std::string host, int port) : host_(std::move(host)), port_(port) {
    std::string target = absl::StrFormat("%s:%d", host_, port_);
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(target, grpc::InsecureChannelCredentials());
    std::unique_ptr<routeguide::RouteGuide::Stub> stub = routeguide::RouteGuide::NewStub(channel);
    context_ptr_ = std::make_shared<grpc::ClientContext>();
    stream_ = stub->RouteChat(context_ptr_.get());
}

void PyClient::write(const PyRequest &request) {
    routeguide::RouteRequest routeRequest;
    routeRequest.set_id(request.id);
    stream_->Write(routeRequest);
}

PyResponse PyClient::read() {
    routeguide::RouteResponse routeResponse;
    stream_->Read(&routeResponse);
    return PyResponse{routeResponse.message()};
}
