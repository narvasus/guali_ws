#!/bin/bash

# Function to convert bytes to megabytes
bytes_to_mb() {
    echo "scale=2; $1 / (1024 * 1024)" | bc
}

while true; do
    clear

    # Get network statistics
    #netstat_output=$(netstat -i | grep eth0)
    netstat_output=$(netstat -i | grep wlan0)

    # Extract sent and received bytes
    received_bytes=$(echo "$netstat_output" | awk '{print $3}')
    sent_bytes=$(echo "$netstat_output" | awk '{print $7}')

    # Convert sent and received bytes to megabytes
    sent_mb=$(bytes_to_mb $sent_bytes)
    received_mb=$(bytes_to_mb $received_bytes)

    # Calculate total bytes
    total_bytes=$((sent_bytes + received_bytes))
    total_mb=$(bytes_to_mb $total_bytes)

    # Get uptime of the machine
    uptime=$(uptime | awk '{print $3,$4}' | sed 's/,//')

    # Calculate MB/hour usage since uptime
    mb_per_hour=$(echo "scale=2; $total_mb * 60 / ${uptime//[^0-9]/}" | bc)

    # Display results
    echo "Data transmision in session Statistics:"
    echo "Sent:       $sent_mb MB"
    echo "Received:   $received_mb MB"
    echo "Total:      $total_mb MB"
    echo "Uptime:     $uptime"
    echo "MB/hour:    $mb_per_hour MB/hour"

    # Sleep for 1 second before refreshing
    sleep 1
done
