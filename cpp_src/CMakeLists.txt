cmake_minimum_required(VERSION 3.28)
cmake_policy(SET CMP0135 NEW)
project(casual_pre_loader_cpp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT EXISTS "${CMAKE_SOURCE_DIR}/include/nlohmann/json.hpp")
    file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/include/nlohmann")
    file(DOWNLOAD 
        "https://github.com/nlohmann/json/releases/download/v3.11.2/json.hpp"
        "${CMAKE_SOURCE_DIR}/include/nlohmann/json.hpp"
    )
endif()

if(NOT EXISTS "${CMAKE_SOURCE_DIR}/include/argparse/argparse.hpp")
    file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/include/argparse")
    file(DOWNLOAD 
        "https://raw.githubusercontent.com/p-ranav/argparse/v2.9/include/argparse/argparse.hpp"
        "${CMAKE_SOURCE_DIR}/include/argparse/argparse.hpp"
    )
endif()

include_directories(include)

set(SOURCES
    src/main.cpp
    src/core/ModManager.cpp
    src/core/VPKHandler.cpp
    src/core/PCFHandler.cpp
    src/core/ConfigLoader.cpp
    src/core/BackupManager.cpp
    src/utils/Logger.cpp
)

set(HEADERS
    src/core/ModManager.hpp
    src/core/VPKHandler.hpp
    src/core/PCFHandler.hpp
    src/core/ConfigLoader.hpp
    src/core/BackupManager.hpp
    src/utils/Logger.hpp
    src/utils/BinaryStream.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

enable_testing()
