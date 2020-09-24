; Auto-generated. Do not edit!


(cl:in-package gins-msg)


;//! \htmlinclude ins.msg.html

(cl:defclass <ins> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (position
    :reader position
    :initarg :position
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (velocity
    :reader velocity
    :initarg :velocity
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (attitude
    :reader attitude
    :initarg :attitude
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (acc_bias
    :reader acc_bias
    :initarg :acc_bias
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (gyr_bias
    :reader gyr_bias
    :initarg :gyr_bias
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (ant_lever_arm
    :reader ant_lever_arm
    :initarg :ant_lever_arm
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3)))
)

(cl:defclass ins (<ins>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ins>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ins)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name gins-msg:<ins> is deprecated: use gins-msg:ins instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ins>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gins-msg:header-val is deprecated.  Use gins-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <ins>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gins-msg:position-val is deprecated.  Use gins-msg:position instead.")
  (position m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <ins>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gins-msg:velocity-val is deprecated.  Use gins-msg:velocity instead.")
  (velocity m))

(cl:ensure-generic-function 'attitude-val :lambda-list '(m))
(cl:defmethod attitude-val ((m <ins>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gins-msg:attitude-val is deprecated.  Use gins-msg:attitude instead.")
  (attitude m))

(cl:ensure-generic-function 'acc_bias-val :lambda-list '(m))
(cl:defmethod acc_bias-val ((m <ins>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gins-msg:acc_bias-val is deprecated.  Use gins-msg:acc_bias instead.")
  (acc_bias m))

(cl:ensure-generic-function 'gyr_bias-val :lambda-list '(m))
(cl:defmethod gyr_bias-val ((m <ins>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gins-msg:gyr_bias-val is deprecated.  Use gins-msg:gyr_bias instead.")
  (gyr_bias m))

(cl:ensure-generic-function 'ant_lever_arm-val :lambda-list '(m))
(cl:defmethod ant_lever_arm-val ((m <ins>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gins-msg:ant_lever_arm-val is deprecated.  Use gins-msg:ant_lever_arm instead.")
  (ant_lever_arm m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ins>) ostream)
  "Serializes a message object of type '<ins>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'position) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'velocity) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'attitude) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'acc_bias) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'gyr_bias) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'ant_lever_arm) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ins>) istream)
  "Deserializes a message object of type '<ins>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'position) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'velocity) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'attitude) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'acc_bias) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'gyr_bias) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'ant_lever_arm) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ins>)))
  "Returns string type for a message object of type '<ins>"
  "gins/ins")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ins)))
  "Returns string type for a message object of type 'ins"
  "gins/ins")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ins>)))
  "Returns md5sum for a message object of type '<ins>"
  "ffa3347d032977e6b6132691084d732b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ins)))
  "Returns md5sum for a message object of type 'ins"
  "ffa3347d032977e6b6132691084d732b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ins>)))
  "Returns full string definition for message of type '<ins>"
  (cl:format cl:nil "~%std_msgs/Header header~%~%geometry_msgs/Vector3 position~%geometry_msgs/Vector3 velocity~%geometry_msgs/Vector3 attitude~%~%geometry_msgs/Vector3 acc_bias~%geometry_msgs/Vector3 gyr_bias~%~%geometry_msgs/Vector3 ant_lever_arm~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ins)))
  "Returns full string definition for message of type 'ins"
  (cl:format cl:nil "~%std_msgs/Header header~%~%geometry_msgs/Vector3 position~%geometry_msgs/Vector3 velocity~%geometry_msgs/Vector3 attitude~%~%geometry_msgs/Vector3 acc_bias~%geometry_msgs/Vector3 gyr_bias~%~%geometry_msgs/Vector3 ant_lever_arm~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ins>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'position))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'velocity))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'attitude))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'acc_bias))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'gyr_bias))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'ant_lever_arm))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ins>))
  "Converts a ROS message object to a list"
  (cl:list 'ins
    (cl:cons ':header (header msg))
    (cl:cons ':position (position msg))
    (cl:cons ':velocity (velocity msg))
    (cl:cons ':attitude (attitude msg))
    (cl:cons ':acc_bias (acc_bias msg))
    (cl:cons ':gyr_bias (gyr_bias msg))
    (cl:cons ':ant_lever_arm (ant_lever_arm msg))
))
