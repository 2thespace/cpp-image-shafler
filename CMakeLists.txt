cmake_minimum_required(VERSION 3.5)

project(tst)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/out)
# include_directories(json/include)


set(SRC common.hpp
Shaffler.hpp Shaffler.cpp
ImageReader.hpp ImageReader.cpp
ImageShaffler.hpp ImageShaffler.cpp
ImageCoder.hpp ImageCoder.cpp
)

add_executable(tests  main.cpp
               ${SRC}         
)

target_include_directories(tests PRIVATE ${CMAKE_CURRENT_LIST_DIR}/third-party)

add_executable(encoder  encoder.cpp
               ${SRC}         
)

target_include_directories(encoder PRIVATE ${CMAKE_CURRENT_LIST_DIR}/third-party)

add_executable(decoder  decoder.cpp
               ${SRC}         
)

target_include_directories(decoder PRIVATE ${CMAKE_CURRENT_LIST_DIR}/third-party)

