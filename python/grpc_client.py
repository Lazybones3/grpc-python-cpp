import grpc
import queue

import route_guide_pb2
import route_guide_pb2_grpc

if __name__ == '__main__':
    channel = grpc.insecure_channel('127.0.0.1:50051')
    stub = route_guide_pb2_grpc.RouteGuideStub(channel)

    send_queue = queue.SimpleQueue()
    stream = stub.RouteChat(iter(send_queue.get, None))
    for i in range(100):
        req = route_guide_pb2.RouteRequest(id=i+1)
        send_queue.put(req)
        resp = next(stream)
        print(f"Client received: {resp.message}")
