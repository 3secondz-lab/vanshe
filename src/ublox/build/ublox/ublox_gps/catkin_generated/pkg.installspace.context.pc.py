# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "tf;roscpp;ublox_msgs;ublox_serialization".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lublox_gps".split(';') if "-lublox_gps" != "" else []
PROJECT_NAME = "ublox_gps"
PROJECT_SPACE_DIR = "/home/rnd/ros/ublox_ws/install"
PROJECT_VERSION = "1.3.1"
