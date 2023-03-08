cmake_minimum_required(VERSION 3.2)
project(ceres-core)

set(PROJECT_NAME ceres-core)
set(CMAKE_CXX_STANDARD 17)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

set(TARGET_NAME_BROWSER ceres-core)
set(TARGET_NAME_NODE ceres-core.node)

set(EMSDK_FLAGS
    "-s WASM=1\
    -s USE_ES6_IMPORT_META=1\
    -s EXPORT_ES6=1\
    -O3\
    -s EXPORT_NAME='createModule'\
    -s EXPORTED_FUNCTIONS='[\"_malloc\", \"_free\"]'\
    -s EXTRA_EXPORTED_RUNTIME_METHODS='[\"ccall\",\"cwrap\"]'\
    -s EXPORTED_RUNTIME_METHODS='FS'\
    -s ENVIRONMENT='web,webview,worker'\
    -s ALLOW_MEMORY_GROWTH=1\
    -s FORCE_FILESYSTEM=1\
    ")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${EMSDK_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EMSDK_FLAGS}")

find_package(Ceres REQUIRED)

# -s Release\
# MEMO : ceres lib cmake에서 find_package(thread) 삭제
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CERES_INCLUDE_DIRS}
    ${BOOST_INCLUDE}
    ${PCL_INCLUDE}
    ${FLANN_INCLUDE}
    ${EIGEN_INCLUDE}
)
link_directories(
    ${PCL_LIB}
    ${FLANN_LIB}
    ${BOOST_LIB}
)

file(GLOB PCL_LINK_LIBS ${PCL_LIB}/*.a)
file(GLOB SRCS *.cpp)

# add_executable(extrinsicCalib
# ${SRC_DIR}/cam_lidar_extrinsic.cpp
# )
add_executable(${TARGET_NAME_BROWSER} API.cpp ./src/operation.cpp)

# add_executable(${TARGET_NAME_NODE} ${SRCS})
target_link_libraries(${TARGET_NAME_BROWSER} ${CERES_LIBRARIES})

# target_link_libraries(${TARGET_NAME_NODE}${CERES_LIBRARIES})
