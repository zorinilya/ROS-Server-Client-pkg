// Auto-generated. Do not edit!

// (in-package server.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class PositionRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.X = null;
    }
    else {
      if (initObj.hasOwnProperty('X')) {
        this.X = initObj.X
      }
      else {
        this.X = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PositionRequest
    // Serialize message field [X]
    bufferOffset = _serializer.int64(obj.X, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PositionRequest
    let len;
    let data = new PositionRequest(null);
    // Deserialize message field [X]
    data.X = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'server/PositionRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1e404dd3cb6d4bfb308931d7bf3cfb43';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 X
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PositionRequest(null);
    if (msg.X !== undefined) {
      resolved.X = msg.X;
    }
    else {
      resolved.X = 0
    }

    return resolved;
    }
};

class PositionResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.X = null;
    }
    else {
      if (initObj.hasOwnProperty('X')) {
        this.X = initObj.X
      }
      else {
        this.X = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PositionResponse
    // Serialize message field [X]
    bufferOffset = _serializer.int64(obj.X, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PositionResponse
    let len;
    let data = new PositionResponse(null);
    // Deserialize message field [X]
    data.X = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'server/PositionResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1e404dd3cb6d4bfb308931d7bf3cfb43';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 X
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PositionResponse(null);
    if (msg.X !== undefined) {
      resolved.X = msg.X;
    }
    else {
      resolved.X = 0
    }

    return resolved;
    }
};

module.exports = {
  Request: PositionRequest,
  Response: PositionResponse,
  md5sum() { return '36c8dcf1c5586f27520f2080e30f4ae0'; },
  datatype() { return 'server/Position'; }
};
