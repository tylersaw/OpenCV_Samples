find_package(OpenCV REQUIRED)
add_executable(detect_mouse main.cpp)
target_link_libraries(detect_mouse ${OpenCV_LIBS})
