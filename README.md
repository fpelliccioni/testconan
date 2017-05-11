# zmq-protobuf-test
C++ ZeroMQ Google Protocol Buffer Tests, using Conan.io, CMake, Travis-CI and Appveyor

VS 2015

$ mkdir && cd build
$ conan install ..
$ cmake .. -G "Visual Studio 14 Win64"
$ cmake --build . --config Release
$ cd bin
$ server
# other terminal
$ client


VS 2017

$ mkdir && cd build
$ conan install .. -s compiler="Visual Studio" -s compiler.version=15 --build=missing
$ cmake .. -G "Visual Studio 15 Win64"
$ cmake --build . --config Release
$ cd bin
$ server
# other terminal
$ client
