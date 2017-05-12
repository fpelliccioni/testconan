project(ZMQ-Protobuf)
cmake_minimum_required(VERSION 3.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# find_package(
#        Boost 1.56.0 REQUIRED
#        COMPONENTS regex)

set(Protobuf_LIBRARY ${CONAN_PROTOBUF_ROOT})
find_package(Protobuf)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${CMAKE_SOURCE_DIR}/message.proto)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(message message.pb.cc)
add_executable(client client.cpp)
add_executable(server server.cpp)

target_link_libraries(client message ${CONAN_LIBS})
target_link_libraries(server message ${CONAN_LIBS})
