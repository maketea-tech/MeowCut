aux_source_directory(. src_files)
set(target_sources_files)
foreach(src_file ${src_files})
    list(APPEND target_sources_files ${CMAKE_CURRENT_SOURCE_DIR}/${src_file})
endforeach()

list(APPEND target_sources_files ${CMAKE_CURRENT_SOURCE_DIR}/avcodec.ui)

target_sources(${PROJECT_NAME} PRIVATE ${target_sources_files})

message("message source file is ${target_sources_files}")
