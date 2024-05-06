source /home/jetson/guali_ws/install/setup.bash
ros2 pkg list | grep detectabasura

xterm -geometry 63x10+1020+315 -hold -e "rqt"& 
xterm -geometry 63x10+1720+155 -hold -e "ros2 run detectabasura video_publisher"&
sleep 8s
xterm -geometry 63x25+1720+315  -hold -e "ros2 run camera_calibration cameracalibrator --approximate 0.1 --size 9x7 --square 0.02 --ros-args --remap right:=/image_right --ros-args --remap left:=/image_left"&


# Prompt the user to press a key
echo "Press any key to close all runing programs..."
read -n 1 -s
pkill xterm
