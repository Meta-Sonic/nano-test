cmake_minimum_required(VERSION 3.21)

project(request)
 
# All sources.
file(GLOB_RECURSE REQUEST_INCLUDE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

file(GLOB_RECURSE REQUEST_SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.m"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.mm"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

# File groups.
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${REQUEST_INCLUDE_FILES} ${REQUEST_SOURCE_FILES})

add_executable(${PROJECT_NAME} ${REQUEST_INCLUDE_FILES} ${REQUEST_SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    utest
    "-framework AppKit"
    "-framework Foundation"
)

# set_target_properties(${PROJECT_NAME} PROPERTIES
#     FOLDER ${MTS_EXAMPLES_FOLDER_NAME}
#     RUNTIME_OUTPUT_DIRECTORY ${MTS_EXAMPLES_OUTPUT_DIRECTORY}
# )

target_compile_options(${PROJECT_NAME} PUBLIC
# -Wall
# -Wextra
-Weverything
# -Wno-global-constructors
-Wno-c++98-compat
# -Wpedantic
# -Woverloaded-virtual
# -Wreorder
# -Wuninitialized
# -Wunused-parameter
# -Wshift-sign-overflow
# -Wno-switch
# -Wswitch-enum
# -Wno-ignored-qualifiers
# -Wunused-private-field
# -Wunreachable-code
# -Wcast-align
# -Winconsistent-missing-destructor-override
# -Wnullable-to-nonnull-conversion
# -Wno-missing-field-initializers
# -Wsuggest-override
)