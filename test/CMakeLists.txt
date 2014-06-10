find_package(OpenCV REQUIRED)
add_executable(test main.cpp)
target_link_libraries(test ${OpenCV_LIBS})
