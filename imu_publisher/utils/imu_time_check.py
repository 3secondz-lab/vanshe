#!/usr/bin/env python3

import rospy
import rosbag
from sensor_msgs.msg import *
from matplotlib import pyplot as plt

import argparse

parser = argparse.ArgumentParser(description='Rosbag IMU time checker')
parser.add_argument('--input', type=str, required=False,
                    # default='/home/rnd/Data/200922/2020-09-22-13-42-25.bag',
                    default='/home/rnd/Data/200922/2020-09-22-15-39-31.bag',
                    help='Path to input bag')
parser.add_argument('--topic', type=str, required=False,
                    default='/imu_publisher/imu',
                    # default='/imu/imu',
                    help='Topic name')

args = parser.parse_args()


if __name__ == '__main__':
    bag_in = rosbag.Bag(args.input, 'r')

    print('{}'.format(args.input))

    t_base = 0

    t_bag = []
    t_topic = []
    t_diff = []

    for topic, msg, t in bag_in.read_messages():
        if t_base == 0:
            t_base = t.to_sec()

        if topic == args.topic:
            t_b = t.to_sec() - t_base
            t_t = msg.header.stamp.to_sec() - t_base
            t_d = t_b - t_t

            # if t_b < 119.50 or t_b > 120.0:
            #     continue

            t_bag.append(t_b)
            t_topic.append(t_t)
            t_diff.append(t_d)

            print('seq : {} : {:.16f} / {:.16f} / {:.16f}'.format(msg.header.seq, t_b, t_t, t_d))

    fig = plt.figure()

    ax1 = fig.add_subplot(3, 1, 1)
    ax2 = fig.add_subplot(3, 1, 2)
    ax3 = fig.add_subplot(3, 1, 3)

    ax1.plot(t_bag, t_topic)
    ax1.set_xlabel('Bag')
    ax1.set_ylabel('Topic')
    ax1.set_title('Bag vs. Topic')

    ax2.plot(t_bag, t_diff)
    ax2.set_xlabel('Bag')
    ax2.set_ylabel('Diff')
    ax2.set_title('Bag vs. Diff')

    ax3.plot(t_topic)

    plt.show()

    print('Check finished.')
