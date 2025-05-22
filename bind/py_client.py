import sys
sys.path.append("../cmake-build-debug/bind")
from PyGrpcModule import PyClient, PyRequest

client = PyClient("127.0.0.1", 50051)

for i in range(100):
    req = PyRequest(i+1)
    client.write(req)
    rsp = client.read()
    print("Client received: " + rsp.message)
