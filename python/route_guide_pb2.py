# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# NO CHECKED-IN PROTOBUF GENCODE
# source: route_guide.proto
# Protobuf Python Version: 5.29.0
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import runtime_version as _runtime_version
from google.protobuf import symbol_database as _symbol_database
from google.protobuf.internal import builder as _builder
_runtime_version.ValidateProtobufRuntimeVersion(
    _runtime_version.Domain.PUBLIC,
    5,
    29,
    0,
    '',
    'route_guide.proto'
)
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x11route_guide.proto\x12\nrouteguide\"\x1a\n\x0cRouteRequest\x12\n\n\x02id\x18\x01 \x01(\x05\" \n\rRouteResponse\x12\x0f\n\x07message\x18\x01 \x01(\t2T\n\nRouteGuide\x12\x46\n\tRouteChat\x12\x18.routeguide.RouteRequest\x1a\x19.routeguide.RouteResponse\"\x00(\x01\x30\x01\x62\x06proto3')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'route_guide_pb2', _globals)
if not _descriptor._USE_C_DESCRIPTORS:
  DESCRIPTOR._loaded_options = None
  _globals['_ROUTEREQUEST']._serialized_start=33
  _globals['_ROUTEREQUEST']._serialized_end=59
  _globals['_ROUTERESPONSE']._serialized_start=61
  _globals['_ROUTERESPONSE']._serialized_end=93
  _globals['_ROUTEGUIDE']._serialized_start=95
  _globals['_ROUTEGUIDE']._serialized_end=179
# @@protoc_insertion_point(module_scope)
