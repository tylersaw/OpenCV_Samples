find_package(OpenCV REQUIRED)
add_executable(2D_Linear_Filter main.cpp)
target_link_libraries(2D_Linear_Filter ${OpenCV_LIBS})
