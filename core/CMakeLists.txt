if (_DEMO_TYPE_)
    project(${CORE_TARGET} VERSION ${SOFTWARE_VERSION} LANGUAGES CXX)

    find_package(Qt5 COMPONENTS Widgets REQUIRED)

    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)

    set(EXECUTABLE_OUTPUT_PATH "${CORE_OUTPUT}")

    # 设置src下demo的ui文件
    set(UI_FILES src/${_DEMO_TYPE_}/demo/${_DEMO_TYPE_}.ui)

    # 设置src下demo的源文件
    set(SRC_FILES
        src/main.cpp
        src/${_DEMO_TYPE_}/${_DEMO_TYPE_}.cpp
        src/${_DEMO_TYPE_}/demo/${_DEMO_TYPE_}.cpp
    )

    set(PROJECT_SOURCES
            ${SRC_FILES}
            ${UI_FILES}
    )

    add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)

else()
    project(${CORE_TARGET} VERSION ${SOFTWARE_VERSION} LANGUAGES CXX)

    find_package(Qt5 COMPONENTS Widgets REQUIRED)

    # 设置头文件和库文件生成目录
    set(LIBRARY_OUTPUT_PATH "${CORE_OUTPUT}")

    # 逐一设置src下的目录中的源文件
    set(SRC_FILES
        # audio effect

        # avcodec
        src/avcodec/avcodec.cpp

        # avcodec widget, just for test ???, not add now

        # avsync

        # image_filter

        # meowcutcore
        src/meowcut_core/meowcut_core.cpp

        # video render
    )

    add_library(${PROJECT_NAME} SHARED ${SRC_FILES})
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)

    # 拷贝部署需要的头文件???
    # file(COPY include/*.h DESTINATION ${LIBRARY_OUTPUT_PATH}/include FOLLOW_SYMLINK_CHAIN)
    # file(COPY include/avcodec/*.h DESTINATION ${LIBRARY_OUTPUT_PATH}/include/avcodec FOLLOW_SYMLINK_CHAIN)
    # file(COPY include/meowcutcore/*.h DESTINATION ${LIBRARY_OUTPUT_PATH}/include/meowcutcore FOLLOW_SYMLINK_CHAIN)

endif()
