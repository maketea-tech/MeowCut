cmake_minimum_required(VERSION 3.5)

project(4build)

# 设置使用ccache
find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
endif()

# 安装路径
if (NOT INSTALL_PREFIX)
    set(INSTALL_PREFIX "${CMAKE_CURRENT_LIST_DIR}/bin/${CMAKE_SYSTEM_NAME}")
elseif(${INSTALL_PREFIX} STREQUAL "." OR ${INSTALL_PREFIX} STREQUAL "./")
    set(INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}")
else()
    set(INSTALL_PREFIX "${INSTALL_PREFIX}/bin/${CMAKE_SYSTEM_NAME}")
endif()

# 软件版本
if(NOT DEFINED SOFTWARE_VERSION)
    set(SOFTWARE_VERSION "0.1")
endif()

# 指定编译器标准
if(NOT DEFINED CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
else()
    set(CMAKE_CXX_STANDARD ${CXX_STANDARD})
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 编译选项
if (NOT CMAKE_BUILD_TYPE)
    message("CMAKE_BUILD_TYPE not set, default is debug mode")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
    add_definitions(-DDEBUG)
else()
    if(${CMAKE_BUILD_TYPE} STREQUAL "release")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
    elseif(${CMAKE_BUILD_TYPE} STREQUAL "debug")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")    # -g
        add_definitions(-DDEBUG)                        # 增加debug宏，开启源码中的DEBUG能力
    else()          # 没有指定就使用debug模式
        message(FATAL_ERROR "CMAKE_BUILD_TYPE not supported")
    endif()
endif()

# QT5 path
if (NOT "$ENV{QT_DIR}" STREQUAL "")     # 配置自己的qt路径，对于qt5需要包含Qt5Config.cmake文件
    set(Qt5_DIR "$ENV{QT_DIR}")
else()
    if (NOT "$ENV{Qt5_DIR}" STREQUAL "")
        set(Qt5_DIR "$ENV{Qt5_DIR}")
    else()
        if (NOT "${Qt_Path}" STREQUAL "")
            set(Qt5_DIR "${Qt_Path}")
        else()
            message(FATAL_ERROR "Qt_Path and Qt env both not set")
        endif()
    endif()
endif()

# 指定头文件路径
    # app
set(APP_PATH "${CMAKE_CURRENT_LIST_DIR}/app")
include_directories("${APP_PATH}/src")
include_directories("${APP_PATH}/include")
set(APP_OUTPUT "${INSTALL_PREFIX}")
set(APP_NAME "MeowCut")

    # core
set(CORE_PATH "${CMAKE_CURRENT_LIST_DIR}/core")
include_directories("${CORE_PATH}/src")
include_directories("${CORE_PATH}/third_party")
include_directories("${CORE_PATH}/include")
set(CORE_OUTPUT "${INSTALL_PREFIX}")
set(CORE_TARGET "MeowCutCore")

if (NOT DEFINED SOFTWARE_TYPE)
    add_subdirectory("${CORE_PATH}")
    add_subdirectory("${APP_PATH}")
else()
    if ("${SOFTWARE_TYPE}" STREQUAL "lib")      # build lib only
        add_subdirectory("${CORE_PATH}")
    elseif("${SOFTWARE_TYPE}" STREQUAL "app")                                      # build lib and app
        add_subdirectory("${CORE_PATH}")
        add_subdirectory("${APP_PATH}")
    else()
        message(FATAL_ERROR "SOFTWARE_TYPE not suooprted")
    endif()
endif()
