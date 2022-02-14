cmake_minimum_required(VERSION 3.5)

project(MeowCutBuild)

# 手动设置参数，visual studio使用
set(Qt_Path "D:\\install\\qt\\5.14.0\\msvc2017_64\\lib\\cmake\\Qt5")
set(SOFTWARE_TYPE "demo")
set(DEMO_TYPE "avcodec")
set(CMAKE_BUILD_TYPE "debug")
set(SOFTWARE_VERSION "1.0")
set(INSTALL_PREFIX "")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)


# 设置使用ccache
find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
endif()

message("message: cmake current binary dir is ${CMAKE_CURRENT_BINARY_DIR}")
message("message: cmake system name is ${CMAKE_SYSTEM_NAME}")

# 安装路径
if (NOT INSTALL_PREFIX)
    set(INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}")
elseif(${INSTALL_PREFIX} STREQUAL "." OR ${INSTALL_PREFIX} STREQUAL "./")
    set(INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}")
else()
    set(INSTALL_PREFIX "${INSTALL_PREFIX}/bin/${CMAKE_SYSTEM_NAME}")
endif()

message("message: cmake install prefix is ${INSTALL_PREFIX}")

# 软件版本
if(NOT DEFINED SOFTWARE_VERSION)
    set(SOFTWARE_VERSION "0.1")
endif()

# 编译选项
if (NOT CMAKE_BUILD_TYPE)    # 没有指定就使用debug模式
    message("CMAKE_BUILD_TYPE not set, default is debug mode")
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" 
            OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
    else()      # MSVC下-g不能用
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    endif()
    add_definitions(-DDEBUG)
else()
    string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
    if(${BUILD_TYPE} STREQUAL "release")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
    elseif(${BUILD_TYPE} STREQUAL "relwithdebinfo")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
    elseif(${BUILD_TYPE} STREQUAL "debug")
        if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" 
                OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
        else()      # MSVC下-g不能用
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
        endif()
        add_definitions(-DDEBUG)                        # 增加debug宏，开启源码中的DEBUG能力
    else()
        message(FATAL_ERROR "CMAKE_BUILD_TYPE(${CMAKE_BUILD_TYPE}) not supported")
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
set(APP_TARGET "MeowCut")

    # core
set(CORE_PATH "${CMAKE_CURRENT_LIST_DIR}/core")
include_directories("${CORE_PATH}/src")
include_directories("${CORE_PATH}/third_party")
include_directories("${CORE_PATH}/include")
set(CORE_OUTPUT "${INSTALL_PREFIX}")
set(CORE_TARGET "${APP_TARGET}Core")

find_package(OpenGL REQUIRED)

if (OPENGL_FOUND)
    message("opengl found")
    message("include dir: ${OPENGL_INCLUDE_DIR}")
    message("link libraries: ${OPENGL_gl_LIBRARY}")
else (OPENGL_FOUND)
    message("opengl not found")
endif()

if (NOT DEFINED SOFTWARE_TYPE)
    add_subdirectory("${CORE_PATH}")
    add_subdirectory("${APP_PATH}")
else()
    string(TOLOWER ${SOFTWARE_TYPE} _SOFTWARE_TYPE_)
    if ("${_SOFTWARE_TYPE_}" STREQUAL "lib")      # build lib only
        add_subdirectory("${CORE_PATH}")
    elseif("${_SOFTWARE_TYPE_}" STREQUAL "app")                                      # build lib and app
        add_subdirectory("${CORE_PATH}")
        add_subdirectory("${APP_PATH}")
    elseif("${_SOFTWARE_TYPE_}" STREQUAL "demo")
        # 设置测试的demo
        if (NOT DEMO_TYPE)
            message(FATAL_ERROR "DEMO_TYPE must set while build demo")
        else()
            string(TOLOWER ${DEMO_TYPE} _DEMO_TYPE_)
            if ("${_DEMO_TYPE_}" STREQUAL "audio_effect")
                add_definitions(-DDEMO_AUDIO_EFFECT)
            elseif("${_DEMO_TYPE_}" STREQUAL "avcodec")
                add_definitions(-DDEMO_AVCODEC)
            elseif("${_DEMO_TYPE_}" STREQUAL "meowcut_core")
                add_definitions(-DDEMO_MEOWCUT_CORE)
            elseif("${_DEMO_TYPE_}" STREQUAL "video_render")
                add_definitions(-DDEMO_VIDEO_RENDER)
            else()
                message(FATAL_ERROR "DEMO_TYPE(${DEMO_TYPE}) not supported")
            endif()
        endif()
        add_definitions(-DDEBUG)            # demo must in debug
        # set(BUILD_DEMO ON)
        add_subdirectory("${CORE_PATH}")
    else()
        message(FATAL_ERROR "SOFTWARE_TYPE(${SOFTWARE_TYPE}) not suooprted")
    endif()
endif()
