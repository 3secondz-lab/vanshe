// Auto-generated. Do not edit!

// (in-package gins.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ins {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.position = null;
      this.velocity = null;
      this.attitude = null;
      this.acc_bias = null;
      this.gyr_bias = null;
      this.ant_lever_arm = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('velocity')) {
        this.velocity = initObj.velocity
      }
      else {
        this.velocity = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('attitude')) {
        this.attitude = initObj.attitude
      }
      else {
        this.attitude = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('acc_bias')) {
        this.acc_bias = initObj.acc_bias
      }
      else {
        this.acc_bias = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('gyr_bias')) {
        this.gyr_bias = initObj.gyr_bias
      }
      else {
        this.gyr_bias = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('ant_lever_arm')) {
        this.ant_lever_arm = initObj.ant_lever_arm
      }
      else {
        this.ant_lever_arm = new geometry_msgs.msg.Vector3();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ins
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [position]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.position, buffer, bufferOffset);
    // Serialize message field [velocity]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.velocity, buffer, bufferOffset);
    // Serialize message field [attitude]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.attitude, buffer, bufferOffset);
    // Serialize message field [acc_bias]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.acc_bias, buffer, bufferOffset);
    // Serialize message field [gyr_bias]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.gyr_bias, buffer, bufferOffset);
    // Serialize message field [ant_lever_arm]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.ant_lever_arm, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ins
    let len;
    let data = new ins(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [position]
    data.position = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [velocity]
    data.velocity = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [attitude]
    data.attitude = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [acc_bias]
    data.acc_bias = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [gyr_bias]
    data.gyr_bias = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [ant_lever_arm]
    data.ant_lever_arm = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 144;
  }

  static datatype() {
    // Returns string type for a message object
    return 'gins/ins';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ffa3347d032977e6b6132691084d732b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
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
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ins(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.position !== undefined) {
      resolved.position = geometry_msgs.msg.Vector3.Resolve(msg.position)
    }
    else {
      resolved.position = new geometry_msgs.msg.Vector3()
    }

    if (msg.velocity !== undefined) {
      resolved.velocity = geometry_msgs.msg.Vector3.Resolve(msg.velocity)
    }
    else {
      resolved.velocity = new geometry_msgs.msg.Vector3()
    }

    if (msg.attitude !== undefined) {
      resolved.attitude = geometry_msgs.msg.Vector3.Resolve(msg.attitude)
    }
    else {
      resolved.attitude = new geometry_msgs.msg.Vector3()
    }

    if (msg.acc_bias !== undefined) {
      resolved.acc_bias = geometry_msgs.msg.Vector3.Resolve(msg.acc_bias)
    }
    else {
      resolved.acc_bias = new geometry_msgs.msg.Vector3()
    }

    if (msg.gyr_bias !== undefined) {
      resolved.gyr_bias = geometry_msgs.msg.Vector3.Resolve(msg.gyr_bias)
    }
    else {
      resolved.gyr_bias = new geometry_msgs.msg.Vector3()
    }

    if (msg.ant_lever_arm !== undefined) {
      resolved.ant_lever_arm = geometry_msgs.msg.Vector3.Resolve(msg.ant_lever_arm)
    }
    else {
      resolved.ant_lever_arm = new geometry_msgs.msg.Vector3()
    }

    return resolved;
    }
};

module.exports = ins;
