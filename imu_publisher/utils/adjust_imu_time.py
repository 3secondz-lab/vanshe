#!/usr/bin/env python3

import rospy
import rosbag
from std_msgs.msg import *
from openpilot.msg import *

import argparse

parser = argparse.ArgumentParser(description='Rosbag IMU time adjustor')
parser.add_argument('--input', type=str, required=True, help='Path to input bag')
parser.add_argument('--output', type=str, required=True, help='Path to output bag')
parser.add_argument('--t', type=float, required=False, default=0.7, help='Adjust time in secs')
parser.add_argument('--topic', type=str, required=False, default='/imu/data', help='Topic name')

args = parser.parse_args()


if __name__ == '__main__':
    bag_in = rosbag.Bag(args.input, 'r')
    bag_out = rosbag.Bag(args.output, 'w')

    t_adj_ns = args.t*1e9

    for topic, msg, t in bag_in.read_messages():
        if topic == args.topic:
            t = rospy.Time.from_sec((t.to_nsec() - t_adj_ns)*1e-9)

        bag_out.write(topic, msg, t)

    bag_out.close()

    print('Adjustment finished.')
