if (_DEMO_TYPE_)
    project(${_DEMO_TYPE_} VERSION ${SOFTWARE_VERSION} LANGUAGES CXX)

    find_package(Qt5 COMPONENTS Widgets REQUIRED)

    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)

    set(EXECUTABLE_OUTPUT_PATH "${CORE_OUTPUT}")

    add_executable(${PROJECT_NAME})

    if ("${_DEMO_TYPE_}" STREQUAL "audio_effect")
    elseif("${_DEMO_TYPE_}" STREQUAL "avcodec")
        add_subdirectory(src/avcodec)
        add_subdirectory(avcodec_demo)
    elseif("${_DEMO_TYPE_}" STREQUAL "meowcut_core")
    elseif("${_DEMO_TYPE_}" STREQUAL "video_render")
    else()
        message(FATAL_ERROR "DEMO_TYPE(${DEMO_TYPE}) not supported")
    endif()

    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets ${OPENGL_gl_LIBRARY})

else()
    project(${CORE_TARGET} VERSION ${SOFTWARE_VERSION} LANGUAGES CXX)

    find_package(Qt5 COMPONENTS Widgets REQUIRED)

    # 设置头文件和库文件生成目录
    set(LIBRARY_OUTPUT_PATH "${CORE_OUTPUT}")

    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        add_library(${PROJECT_NAME} STATIC ${MEOW_SRC_FILES})
    else()
        add_library(${PROJECT_NAME} SHARED ${MEOW_SRC_FILES})
    endif()

    add_subdirectory(src)

    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets ${OPENGL_gl_LIBRARY})

    # 拷贝部署需要的头文件???
    # file(COPY include/*.h DESTINATION ${LIBRARY_OUTPUT_PATH}/include FOLLOW_SYMLINK_CHAIN)
    # file(COPY include/avcodec/*.h DESTINATION ${LIBRARY_OUTPUT_PATH}/include/avcodec FOLLOW_SYMLINK_CHAIN)
    # file(COPY include/meowcutcore/*.h DESTINATION ${LIBRARY_OUTPUT_PATH}/include/meowcutcore FOLLOW_SYMLINK_CHAIN)

endif()
