cmake_minimum_required(VERSION 3.5)
project(detectabasura)

# Set CMAKE_BUILD_TYPE to Release to suppress log output during build
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

# Find required packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED) 
find_package(rosidl_default_generators REQUIRED)  


# Use OpenCV 4.6 from the specified path
find_package(OpenCV 4.6 REQUIRED PATHS /usr/share/opencv4)

set(EXEC_NAMES
  video_publisher
)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/SixDOFArmControl.msg"  # Add this line to include SixDOFArmControl.msg
)

foreach(EXEC_NAME ${EXEC_NAMES})
    add_executable(${EXEC_NAME} src/${EXEC_NAME}.cpp)
    ament_target_dependencies(${EXEC_NAME}
      rclcpp
      sensor_msgs
      cv_bridge
      OpenCV
      yaml-cpp
    )
    target_compile_definitions(${EXEC_NAME} PRIVATE "CV_VERSION_EPOCH=4")
    target_link_libraries(${EXEC_NAME}
      ${OpenCV_LIBRARIES}
      Qt5::Widgets  # Link with Qt libraries
    )
    
    # Redirect stdout and stderr to a log file
    set_target_properties(${EXEC_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
    )
endforeach()

install(TARGETS ${EXEC_NAMES}
  DESTINATION lib/${PROJECT_NAME}
)

include_directories(
  ${ament_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  ${sensor_msgs_INCLUDE_DIRS}
  ${YAML_CPP_INCLUDE_DIR}
)

ament_package()