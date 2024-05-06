source /home/jetson/guali_ws/install/setup.bash
ros2 pkg list | grep detectabasura
colcon build

domain="guali.ddns.net"
ip_address=$(dig +short "$domain")
# Check if the IP address is empty or not
if [ -z "$ip_address" ]; then
    echo "Error: Failed to retrieve the IP address for $domain."
else
    echo "The IP address of $domain is: $ip_address"
fi
export ROS_DISCOVERY_SERVER="$ip_address:11811"


###########test talker listener#########
#ros2 run demo_nodes_cpp talker --ros-args --remap __node:=talker_discovery_server
#xterm -geometry 63x10+1720+155 -hold -e "ros2 run detectabasura video_publisher"&
ros2 run detectabasura video_publisher

# Prompt the user to press a key
echo "Press any key to close all runing programs..."
read -n 1 -s
pkill xterm




