find_package( OpenCV REQUIRED )
add_executable( video_read video_read.cpp )
target_link_libraries( video_read ${OpenCV_LIBS} )
