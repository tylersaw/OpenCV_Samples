find_package(OpenCV REQUIRED)
add_executable(Background_Modeling Background_Modeling.cpp)
target_link_libraries(Background_Modeling  ${OpenCV_LIBS})
