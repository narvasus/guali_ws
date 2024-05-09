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

#!/bin/bash

# Get the process IDs associated with /dev/video0 and /dev/video1
pids_video0=$(lsof /dev/video0 | awk 'NR>1 {print $2}')
pids_video1=$(lsof /dev/video1 | awk 'NR>1 {print $2}')

# Kill the processes using /dev/video0
for pid in $pids_video0
do
    echo "Killing process $pid using /dev/video2"
    kill -9 $pid
done

# Kill the processes using /dev/video1
for pid in $pids_video1
do
    echo "Killing process $pid using /dev/video3"
    kill -9 $pid
done



###########test talker listener#########
#ros2 run demo_nodes_cpp talker
#xterm -geometry 63x10+1720+155 -hold -e "ros2 run detectabasura video_publisher"&
ros2 run detectabasura video_publisher_usb & 

# Prompt the user to press a key
echo "Press any key to close all runing programs..."
read -n 1 -s
pkill xterm




