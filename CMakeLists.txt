cmake_minimum_required(VERSION 3.12)
project(Wallet)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")

add_executable(Wallet main.cc wallet.cc wallet.h)