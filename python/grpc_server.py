import grpc
from concurrent import futures

import route_guide_pb2
import route_guide_pb2_grpc


class RouteGuideServicer(route_guide_pb2_grpc.RouteGuideServicer):
    def RouteChat(self, request_iterator, context):
        for req in request_iterator:
            print("Server received: ", req.id)
            resp = route_guide_pb2.RouteResponse(message=f'hello {req.id}')
            yield resp


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=2))
    route_guide_pb2_grpc.add_RouteGuideServicer_to_server(
        RouteGuideServicer(), server
    )
    server.add_insecure_port("[::]:50051")
    server.start()
    server.wait_for_termination()

if __name__ == '__main__':
    serve()
