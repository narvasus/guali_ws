#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/cudastereo.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <rclcpp/publisher.hpp>
#include <opencv2/cudaarithm.hpp>
#include <chrono>
#include <thread>
#include <QApplication>
#include <QSlider>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QSpinBox>

void publishImage(const cv::Mat &image, const std::string &topic_name, const std::string &image_encoding, const rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr &publisher)
{
    // Convert OpenCV image to ROS message
    cv_bridge::CvImage cv_image;
    cv_image.image = image;
    cv_image.encoding = image_encoding;

    // Create ROS message
    sensor_msgs::msg::Image ros_image = *cv_image.toImageMsg();

    // Publish the ROS message
    publisher->publish(ros_image);
}


int main(int argc, char *argv[])
{
 // Define the GStreamer pipeline command for camera 0
    std::string pipeline0 = "nvarguscamerasrc sensor-id=0 ! video/x-raw(memory:NVMM), width=(int)640, height=(int)480, format=(string)NV12, framerate=(fraction)60/1 ! nvvidconv flip-method=0 ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";

    // Open the GStreamer pipeline for camera 0
    cv::VideoCapture camera0_capture(pipeline0, cv::CAP_GSTREAMER);
    if (!camera0_capture.isOpened()) {
        std::cerr << "Failed to open camera 0." << std::endl;
        return -1;
    }

    // Define the GStreamer pipeline command for camera 1
    std::string pipeline1 = "nvarguscamerasrc sensor-id=1 ! video/x-raw(memory:NVMM), width=(int)640, height=(int)480, format=(string)NV12, framerate=(fraction)60/1 ! nvvidconv flip-method=0 ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";

    // Open the GStreamer pipeline for camera 1
    cv::VideoCapture camera1_capture(pipeline1, cv::CAP_GSTREAMER);
    if (!camera1_capture.isOpened()) {
        std::cerr << "Failed to open camera 1." << std::endl;
        return -1;
    }

    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("stereo_cam");

    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_left_pub =
        node->create_publisher<sensor_msgs::msg::Image>("image_left", 10);
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_right_pub =
        node->create_publisher<sensor_msgs::msg::Image>("image_right", 10);


    rclcpp::Rate loop_rate(120); // Adjust the publishing rate as needed 120 works
    while (rclcpp::ok())
    {
        cv::Mat camera1_frame, camera0_frame;
        
        camera0_capture.read(camera0_frame);
        camera1_capture.read(camera1_frame);
       

        // Display and publish frames
        publishImage(camera1_frame, "image_left", sensor_msgs::image_encodings::BGR8, image_left_pub);
        publishImage(camera0_frame, "image_right", sensor_msgs::image_encodings::BGR8, image_right_pub);
        

       
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}