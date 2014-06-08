find_package(OpenCV REQUIRED)
add_executable(histogram main.cpp)
target_link_libraries(histogram ${OpenCV_LIBS})
