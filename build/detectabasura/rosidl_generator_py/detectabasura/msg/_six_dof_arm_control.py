# generated from rosidl_generator_py/resource/_idl.py.em
# with input from detectabasura:msg/SixDOFArmControl.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SixDOFArmControl(type):
    """Metaclass of message 'SixDOFArmControl'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('detectabasura')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'detectabasura.msg.SixDOFArmControl')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__six_dof_arm_control
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__six_dof_arm_control
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__six_dof_arm_control
            cls._TYPE_SUPPORT = module.type_support_msg__msg__six_dof_arm_control
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__six_dof_arm_control

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SixDOFArmControl(metaclass=Metaclass_SixDOFArmControl):
    """Message class 'SixDOFArmControl'."""

    __slots__ = [
        '_servo_a_position',
        '_servo_b_position',
        '_servo_c_position',
        '_servo_d_position',
        '_servo_e_position',
        '_servo_f_position',
    ]

    _fields_and_field_types = {
        'servo_a_position': 'uint8',
        'servo_b_position': 'uint8',
        'servo_c_position': 'uint8',
        'servo_d_position': 'uint8',
        'servo_e_position': 'uint8',
        'servo_f_position': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.servo_a_position = kwargs.get('servo_a_position', int())
        self.servo_b_position = kwargs.get('servo_b_position', int())
        self.servo_c_position = kwargs.get('servo_c_position', int())
        self.servo_d_position = kwargs.get('servo_d_position', int())
        self.servo_e_position = kwargs.get('servo_e_position', int())
        self.servo_f_position = kwargs.get('servo_f_position', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.servo_a_position != other.servo_a_position:
            return False
        if self.servo_b_position != other.servo_b_position:
            return False
        if self.servo_c_position != other.servo_c_position:
            return False
        if self.servo_d_position != other.servo_d_position:
            return False
        if self.servo_e_position != other.servo_e_position:
            return False
        if self.servo_f_position != other.servo_f_position:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def servo_a_position(self):
        """Message field 'servo_a_position'."""
        return self._servo_a_position

    @servo_a_position.setter
    def servo_a_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'servo_a_position' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'servo_a_position' field must be an unsigned integer in [0, 255]"
        self._servo_a_position = value

    @property
    def servo_b_position(self):
        """Message field 'servo_b_position'."""
        return self._servo_b_position

    @servo_b_position.setter
    def servo_b_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'servo_b_position' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'servo_b_position' field must be an unsigned integer in [0, 255]"
        self._servo_b_position = value

    @property
    def servo_c_position(self):
        """Message field 'servo_c_position'."""
        return self._servo_c_position

    @servo_c_position.setter
    def servo_c_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'servo_c_position' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'servo_c_position' field must be an unsigned integer in [0, 255]"
        self._servo_c_position = value

    @property
    def servo_d_position(self):
        """Message field 'servo_d_position'."""
        return self._servo_d_position

    @servo_d_position.setter
    def servo_d_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'servo_d_position' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'servo_d_position' field must be an unsigned integer in [0, 255]"
        self._servo_d_position = value

    @property
    def servo_e_position(self):
        """Message field 'servo_e_position'."""
        return self._servo_e_position

    @servo_e_position.setter
    def servo_e_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'servo_e_position' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'servo_e_position' field must be an unsigned integer in [0, 255]"
        self._servo_e_position = value

    @property
    def servo_f_position(self):
        """Message field 'servo_f_position'."""
        return self._servo_f_position

    @servo_f_position.setter
    def servo_f_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'servo_f_position' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'servo_f_position' field must be an unsigned integer in [0, 255]"
        self._servo_f_position = value
