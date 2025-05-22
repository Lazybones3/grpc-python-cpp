#ifndef GRPCPYTHONCPP_PYCLIENT_H
#define GRPCPYTHONCPP_PYCLIENT_H

#include <grpcpp/grpcpp.h>
#include "../cpp/generated/route_guide.pb.h"
#include "../cpp/generated/route_guide.grpc.pb.h"

struct PyRequest {
    int id;

    explicit PyRequest(int id) : id(id) {}
};

struct PyResponse {
    std::string message;

    explicit PyResponse(std::string message) : message(std::move(message)) {}
};

class PyClient {
public:
    PyClient(std::string host, int port);
    void write(const PyRequest &request);
    PyResponse read();

private:
    std::string host_;
    int port_;
    std::shared_ptr<grpc::ClientContext> context_ptr_;
    std::unique_ptr<grpc::ClientReaderWriter<routeguide::RouteRequest, routeguide::RouteResponse>> stream_;
};


#endif //GRPCPYTHONCPP_PYCLIENT_H
