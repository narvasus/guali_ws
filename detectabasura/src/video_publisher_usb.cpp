#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <std_msgs/msg/string.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include <iostream>
#include <cv_bridge/cv_bridge.h>
#include <rclcpp/publisher.hpp>
#include <cstdlib>
#include <fstream>

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

    cv::VideoCapture camera0_capture(2);
    cv::VideoCapture camera1_capture(3);

    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("stereo_cam_publisher");

    // Publisher for images
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_left_pub =
        node->create_publisher<sensor_msgs::msg::Image>("image_left", 10);
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_right_pub =
        node->create_publisher<sensor_msgs::msg::Image>("image_right", 10);

    // Publisher for calibration data
    auto calibration_publisher = node->create_publisher<std_msgs::msg::String>("stereo_calibration", 1);

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
