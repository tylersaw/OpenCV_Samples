project( kalman_filter )
find_package( OpenCV REQUIRED )
add_executable( kalman_filter kalman_filter.cpp )
target_link_libraries( kalman_filter ${OpenCV_LIBS} )
