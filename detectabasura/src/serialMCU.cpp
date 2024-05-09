// Include necessary headers
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <string>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

using namespace std::chrono_literals;

class SerialPublisher : public rclcpp::Node
{
public:
    SerialPublisher() : Node("serial_publisher")
    {
        // Initialize serial port
        serial_fd_ = open("/dev/ttyUSB0", O_WRONLY | O_NOCTTY);
        if (serial_fd_ == -1)
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to open serial port.");
            return;
        }

        struct termios tty;
        memset(&tty, 0, sizeof(tty));
        if (tcgetattr(serial_fd_, &tty) != 0)
        {
            RCLCPP_ERROR(this->get_logger(), "Error from tcgetattr.");
            return;
        }
        cfsetospeed(&tty, B115200);
        cfsetispeed(&tty, B115200);
        tty.c_cflag |= (CLOCAL | CREAD);
        tty.c_cflag &= ~PARENB;
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CSIZE;
        tty.c_cflag |= CS8;
        tty.c_cc[VMIN] = 1;
        tty.c_cc[VTIME] = 5;
        if (tcsetattr(serial_fd_, TCSANOW, &tty) != 0)
        {
            RCLCPP_ERROR(this->get_logger(), "Error from tcsetattr.");
            return;
        }

        // Create a subscriber to receive data
        subscriber_ = this->create_subscription<std_msgs::msg::String>(
            "serial_router", 10, std::bind(&SerialPublisher::callback, this, std::placeholders::_1));
    }

private:
    void callback(const std_msgs::msg::String::SharedPtr msg)
    {
        // Send received data over serial
        std::string data = msg->data + "\n"; // Add newline character
        write(serial_fd_, data.c_str(), data.length());
    }

    int serial_fd_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SerialPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
