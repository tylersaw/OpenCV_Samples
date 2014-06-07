find_package( OpenCV REQUIRED )
add_executable( thresholding main.cpp )
target_link_libraries( thresholding ${OpenCV_LIBS} )
