# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ublox_msgs/AidHUI.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class AidHUI(genpy.Message):
  _md5sum = "60cd4ce940333cb9b38edd447085ce5c"
  _type = "ublox_msgs/AidHUI"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# AID-HUI (0x0B 0x02)
# GPS Health, UTC and ionosphere parameters
#
# All UBX-AID messages are deprecated; use UBX-MGA messages instead.
# This message contains a health bit mask, UTC time and Klobuchar parameters. For more
# information on these parameters, please see the ICD-GPS-200 documentation.

uint8 CLASS_ID = 11
uint8 MESSAGE_ID = 2

uint32  health          # Bitmask, every bit represents a GPS SV (1-32). 
                        # If the bit is set the SV is healthy.
float64 utcA0           # UTC - parameter A0
float64 utcA1           # UTC - parameter A1
int32   utcTOW          # UTC - reference time of week
int16   utcWNT          # UTC - reference week number
int16   utcLS           # UTC - time difference due to leap seconds before event
int16   utcWNF          # UTC - week number when next leap second event occurs
int16   utcDN           # UTC - day of week when next leap second event occurs
int16   utcLSF          # UTC - time difference due to leap seconds after event
int16   utcSpare        # UTC - Spare to ensure structure is a multiple of 4 
                        # bytes
float32 klobA0          # Klobuchar - alpha 0 [s]
float32 klobA1          # Klobuchar - alpha 1 [s/semicircle]
float32 klobA2          # Klobuchar - alpha 2 [s/semicircle^2]
float32 klobA3          # Klobuchar - alpha 3 [s/semicircle^3]
float32 klobB0          # Klobuchar - beta 0  [s]
float32 klobB1          # Klobuchar - beta 1  [s/semicircle]
float32 klobB2          # Klobuchar - beta 2  [s/semicircle^2]
float32 klobB3          # Klobuchar - beta 3  [s/semicircle^3]
uint32 flags            # flags
uint32 FLAGS_HEALTH = 1     # Healthmask field in this message is valid
uint32 FLAGS_UTC = 2        # UTC parameter fields in this message are valid
uint32 FLAGS_KLOB = 4       # Klobuchar parameter fields in this message are 
                            # valid
"""
  # Pseudo-constants
  CLASS_ID = 11
  MESSAGE_ID = 2
  FLAGS_HEALTH = 1
  FLAGS_UTC = 2
  FLAGS_KLOB = 4

  __slots__ = ['health','utcA0','utcA1','utcTOW','utcWNT','utcLS','utcWNF','utcDN','utcLSF','utcSpare','klobA0','klobA1','klobA2','klobA3','klobB0','klobB1','klobB2','klobB3','flags']
  _slot_types = ['uint32','float64','float64','int32','int16','int16','int16','int16','int16','int16','float32','float32','float32','float32','float32','float32','float32','float32','uint32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       health,utcA0,utcA1,utcTOW,utcWNT,utcLS,utcWNF,utcDN,utcLSF,utcSpare,klobA0,klobA1,klobA2,klobA3,klobB0,klobB1,klobB2,klobB3,flags

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(AidHUI, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.health is None:
        self.health = 0
      if self.utcA0 is None:
        self.utcA0 = 0.
      if self.utcA1 is None:
        self.utcA1 = 0.
      if self.utcTOW is None:
        self.utcTOW = 0
      if self.utcWNT is None:
        self.utcWNT = 0
      if self.utcLS is None:
        self.utcLS = 0
      if self.utcWNF is None:
        self.utcWNF = 0
      if self.utcDN is None:
        self.utcDN = 0
      if self.utcLSF is None:
        self.utcLSF = 0
      if self.utcSpare is None:
        self.utcSpare = 0
      if self.klobA0 is None:
        self.klobA0 = 0.
      if self.klobA1 is None:
        self.klobA1 = 0.
      if self.klobA2 is None:
        self.klobA2 = 0.
      if self.klobA3 is None:
        self.klobA3 = 0.
      if self.klobB0 is None:
        self.klobB0 = 0.
      if self.klobB1 is None:
        self.klobB1 = 0.
      if self.klobB2 is None:
        self.klobB2 = 0.
      if self.klobB3 is None:
        self.klobB3 = 0.
      if self.flags is None:
        self.flags = 0
    else:
      self.health = 0
      self.utcA0 = 0.
      self.utcA1 = 0.
      self.utcTOW = 0
      self.utcWNT = 0
      self.utcLS = 0
      self.utcWNF = 0
      self.utcDN = 0
      self.utcLSF = 0
      self.utcSpare = 0
      self.klobA0 = 0.
      self.klobA1 = 0.
      self.klobA2 = 0.
      self.klobA3 = 0.
      self.klobB0 = 0.
      self.klobB1 = 0.
      self.klobB2 = 0.
      self.klobB3 = 0.
      self.flags = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_I2di6h8fI().pack(_x.health, _x.utcA0, _x.utcA1, _x.utcTOW, _x.utcWNT, _x.utcLS, _x.utcWNF, _x.utcDN, _x.utcLSF, _x.utcSpare, _x.klobA0, _x.klobA1, _x.klobA2, _x.klobA3, _x.klobB0, _x.klobB1, _x.klobB2, _x.klobB3, _x.flags))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 72
      (_x.health, _x.utcA0, _x.utcA1, _x.utcTOW, _x.utcWNT, _x.utcLS, _x.utcWNF, _x.utcDN, _x.utcLSF, _x.utcSpare, _x.klobA0, _x.klobA1, _x.klobA2, _x.klobA3, _x.klobB0, _x.klobB1, _x.klobB2, _x.klobB3, _x.flags,) = _get_struct_I2di6h8fI().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_I2di6h8fI().pack(_x.health, _x.utcA0, _x.utcA1, _x.utcTOW, _x.utcWNT, _x.utcLS, _x.utcWNF, _x.utcDN, _x.utcLSF, _x.utcSpare, _x.klobA0, _x.klobA1, _x.klobA2, _x.klobA3, _x.klobB0, _x.klobB1, _x.klobB2, _x.klobB3, _x.flags))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 72
      (_x.health, _x.utcA0, _x.utcA1, _x.utcTOW, _x.utcWNT, _x.utcLS, _x.utcWNF, _x.utcDN, _x.utcLSF, _x.utcSpare, _x.klobA0, _x.klobA1, _x.klobA2, _x.klobA3, _x.klobB0, _x.klobB1, _x.klobB2, _x.klobB3, _x.flags,) = _get_struct_I2di6h8fI().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_I2di6h8fI = None
def _get_struct_I2di6h8fI():
    global _struct_I2di6h8fI
    if _struct_I2di6h8fI is None:
        _struct_I2di6h8fI = struct.Struct("<I2di6h8fI")
    return _struct_I2di6h8fI
