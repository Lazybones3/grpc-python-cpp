#include <pybind11/pybind11.h>
#include "PyClient.h"

namespace py = pybind11;

PYBIND11_MODULE(PyGrpcModule, m) {
    py::class_<PyClient>(m, "PyClient")
            .def(py::init<std::string, int>())
            .def("read", &PyClient::read)
            .def("write", &PyClient::write);

    py::class_<PyRequest> (m, "PyRequest")
            .def(py::init<int>())
            .def_readwrite("id", &PyRequest::id);

    py::class_<PyResponse> (m, "PyResponse")
            .def(py::init<std::string>())
            .def_readwrite("message", &PyResponse::message);
}
