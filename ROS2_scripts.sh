source /home/jetson/guali_ws/install/setup.bash
ros2 pkg list | grep detectabasura
colcon build
ros2 run detectabasura video_publisher