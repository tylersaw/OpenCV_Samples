find_package(OpenCV REQUIRED)
add_executable(Hough_Circle_Transform main.cpp)
target_link_libraries(Hough_Circle_Transform ${OpenCV_LIBS})
