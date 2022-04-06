include(${PROJECT_SOURCE_DIR}/third_party/fmt.cmake)
include(${PROJECT_SOURCE_DIR}/third_party/spdlog.cmake)
file(GLOB_RECURSE Worker_SRC *.cpp *.hpp)

include_directories(../worker-src)
add_executable(FemWorker ${Worker_SRC})
target_link_libraries(FemWorker
PRIVATE
spdlog
)