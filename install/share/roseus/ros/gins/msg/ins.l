;; Auto-generated. Do not edit!


(when (boundp 'gins::ins)
  (if (not (find-package "GINS"))
    (make-package "GINS"))
  (shadow 'ins (find-package "GINS")))
(unless (find-package "GINS::INS")
  (make-package "GINS::INS"))

(in-package "ROS")
;;//! \htmlinclude ins.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass gins::ins
  :super ros::object
  :slots (_header _position _velocity _attitude _acc_bias _gyr_bias _ant_lever_arm ))

(defmethod gins::ins
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:position __position) (instance geometry_msgs::Vector3 :init))
    ((:velocity __velocity) (instance geometry_msgs::Vector3 :init))
    ((:attitude __attitude) (instance geometry_msgs::Vector3 :init))
    ((:acc_bias __acc_bias) (instance geometry_msgs::Vector3 :init))
    ((:gyr_bias __gyr_bias) (instance geometry_msgs::Vector3 :init))
    ((:ant_lever_arm __ant_lever_arm) (instance geometry_msgs::Vector3 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _position __position)
   (setq _velocity __velocity)
   (setq _attitude __attitude)
   (setq _acc_bias __acc_bias)
   (setq _gyr_bias __gyr_bias)
   (setq _ant_lever_arm __ant_lever_arm)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:position
   (&rest __position)
   (if (keywordp (car __position))
       (send* _position __position)
     (progn
       (if __position (setq _position (car __position)))
       _position)))
  (:velocity
   (&rest __velocity)
   (if (keywordp (car __velocity))
       (send* _velocity __velocity)
     (progn
       (if __velocity (setq _velocity (car __velocity)))
       _velocity)))
  (:attitude
   (&rest __attitude)
   (if (keywordp (car __attitude))
       (send* _attitude __attitude)
     (progn
       (if __attitude (setq _attitude (car __attitude)))
       _attitude)))
  (:acc_bias
   (&rest __acc_bias)
   (if (keywordp (car __acc_bias))
       (send* _acc_bias __acc_bias)
     (progn
       (if __acc_bias (setq _acc_bias (car __acc_bias)))
       _acc_bias)))
  (:gyr_bias
   (&rest __gyr_bias)
   (if (keywordp (car __gyr_bias))
       (send* _gyr_bias __gyr_bias)
     (progn
       (if __gyr_bias (setq _gyr_bias (car __gyr_bias)))
       _gyr_bias)))
  (:ant_lever_arm
   (&rest __ant_lever_arm)
   (if (keywordp (car __ant_lever_arm))
       (send* _ant_lever_arm __ant_lever_arm)
     (progn
       (if __ant_lever_arm (setq _ant_lever_arm (car __ant_lever_arm)))
       _ant_lever_arm)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; geometry_msgs/Vector3 _position
    (send _position :serialization-length)
    ;; geometry_msgs/Vector3 _velocity
    (send _velocity :serialization-length)
    ;; geometry_msgs/Vector3 _attitude
    (send _attitude :serialization-length)
    ;; geometry_msgs/Vector3 _acc_bias
    (send _acc_bias :serialization-length)
    ;; geometry_msgs/Vector3 _gyr_bias
    (send _gyr_bias :serialization-length)
    ;; geometry_msgs/Vector3 _ant_lever_arm
    (send _ant_lever_arm :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; geometry_msgs/Vector3 _position
       (send _position :serialize s)
     ;; geometry_msgs/Vector3 _velocity
       (send _velocity :serialize s)
     ;; geometry_msgs/Vector3 _attitude
       (send _attitude :serialize s)
     ;; geometry_msgs/Vector3 _acc_bias
       (send _acc_bias :serialize s)
     ;; geometry_msgs/Vector3 _gyr_bias
       (send _gyr_bias :serialize s)
     ;; geometry_msgs/Vector3 _ant_lever_arm
       (send _ant_lever_arm :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; geometry_msgs/Vector3 _position
     (send _position :deserialize buf ptr-) (incf ptr- (send _position :serialization-length))
   ;; geometry_msgs/Vector3 _velocity
     (send _velocity :deserialize buf ptr-) (incf ptr- (send _velocity :serialization-length))
   ;; geometry_msgs/Vector3 _attitude
     (send _attitude :deserialize buf ptr-) (incf ptr- (send _attitude :serialization-length))
   ;; geometry_msgs/Vector3 _acc_bias
     (send _acc_bias :deserialize buf ptr-) (incf ptr- (send _acc_bias :serialization-length))
   ;; geometry_msgs/Vector3 _gyr_bias
     (send _gyr_bias :deserialize buf ptr-) (incf ptr- (send _gyr_bias :serialization-length))
   ;; geometry_msgs/Vector3 _ant_lever_arm
     (send _ant_lever_arm :deserialize buf ptr-) (incf ptr- (send _ant_lever_arm :serialization-length))
   ;;
   self)
  )

(setf (get gins::ins :md5sum-) "ffa3347d032977e6b6132691084d732b")
(setf (get gins::ins :datatype-) "gins/ins")
(setf (get gins::ins :definition-)
      "
std_msgs/Header header

geometry_msgs/Vector3 position
geometry_msgs/Vector3 velocity
geometry_msgs/Vector3 attitude

geometry_msgs/Vector3 acc_bias
geometry_msgs/Vector3 gyr_bias

geometry_msgs/Vector3 ant_lever_arm
================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :gins/ins "ffa3347d032977e6b6132691084d732b")


