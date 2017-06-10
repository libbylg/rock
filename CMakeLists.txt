cmake_minimum_required(VERSION 3.3)
project(rock)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

INCLUDE_DIRECTORIES(
    include
)

set(SOURCE_FILES
    include/comm/comm.h
    include/share/CArrayT.h
    include/share/CIdMapT.h
    include/share/CListT.h
    include/share/CMemoryT.h
    include/share/CQueueT.h
    include/share/CValueT.h
    include/share/CVectorT.h
    include/share/type.h
    rock/main.cpp
    src/comm/CCommEnv.cpp
    src/comm/CCommEnv.h
    src/comm/CCommInst.h
    src/comm/CCommSrv.hpp
    src/comm/CCommSrvMgr.h
    src/comm/comm.cpp
    src/comm/comm_global.cpp
    src/comm/TCommMessage.h
    test/comm/test_comm.cpp)

add_executable(rock ${SOURCE_FILES})