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
    src/meowcutcore/meowcutcore.cpp

    # video render
)

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)

# 拷贝部署需要的头文件???
# file(COPY include/*.h DESTINATION ${LIBRARY_OUTPUT_PATH}/include FOLLOW_SYMLINK_CHAIN)
# file(COPY include/avcodec/*.h DESTINATION ${LIBRARY_OUTPUT_PATH}/include/avcodec FOLLOW_SYMLINK_CHAIN)
# file(COPY include/meowcutcore/*.h DESTINATION ${LIBRARY_OUTPUT_PATH}/include/meowcutcore FOLLOW_SYMLINK_CHAIN)
