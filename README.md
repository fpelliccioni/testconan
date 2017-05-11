# zmq-protobuf-test
C++ ZeroMQ Google Protocol Buffer Tests, using Conan.io, CMake, Travis-CI and Appveyor

Tested in VS 2015

$ mkdir && cd build
$ conan install ..
$ cmake .. -G "Visual Studio 14 Win64"
$ cmake --build . --config Release
$ cd bin
$ server
# other terminal
$ client
