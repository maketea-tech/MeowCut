project(${APP_NAME} VERSION ${SOFTWARE_VERSION} LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets OpenGL REQUIRED)

# set(TS_FILES MeowCut_zh_CN.ts)    # 国际化文件，省去吧

set(UI_FILES                    # ui文件集合
        src/meowcut/meowcut.ui
        src/MeowGLWidget/MeowGLWidget.ui
)

set(SRC_FILES                   # 源文件集合
        src/main.cpp
        src/meowcut/meowcut.cpp
        src/MeowGLWidget/MeowGLWidget.cpp
)

set(PROJECT_SOURCES
        ${SRC_FILES}
        ${UI_FILES}
        # ${TS_FILES}
)

set(EXECUTABLE_OUTPUT_PATH "${APP_OUTPUT}")

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
# 国际化
# qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

target_link_libraries(
        ${PROJECT_NAME} PRIVATE 
        Qt5::Widgets Qt5::OpenGL 
        ${CORE_TARGET}
)
