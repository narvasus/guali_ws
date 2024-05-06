// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from detectabasura:msg/SixDOFArmControl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "detectabasura/msg/detail/six_dof_arm_control__rosidl_typesupport_introspection_c.h"
#include "detectabasura/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "detectabasura/msg/detail/six_dof_arm_control__functions.h"
#include "detectabasura/msg/detail/six_dof_arm_control__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void SixDOFArmControl__rosidl_typesupport_introspection_c__SixDOFArmControl_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  detectabasura__msg__SixDOFArmControl__init(message_memory);
}

void SixDOFArmControl__rosidl_typesupport_introspection_c__SixDOFArmControl_fini_function(void * message_memory)
{
  detectabasura__msg__SixDOFArmControl__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember SixDOFArmControl__rosidl_typesupport_introspection_c__SixDOFArmControl_message_member_array[6] = {
  {
    "servo_a_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detectabasura__msg__SixDOFArmControl, servo_a_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "servo_b_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detectabasura__msg__SixDOFArmControl, servo_b_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "servo_c_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detectabasura__msg__SixDOFArmControl, servo_c_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "servo_d_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detectabasura__msg__SixDOFArmControl, servo_d_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "servo_e_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detectabasura__msg__SixDOFArmControl, servo_e_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "servo_f_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detectabasura__msg__SixDOFArmControl, servo_f_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SixDOFArmControl__rosidl_typesupport_introspection_c__SixDOFArmControl_message_members = {
  "detectabasura__msg",  // message namespace
  "SixDOFArmControl",  // message name
  6,  // number of fields
  sizeof(detectabasura__msg__SixDOFArmControl),
  SixDOFArmControl__rosidl_typesupport_introspection_c__SixDOFArmControl_message_member_array,  // message members
  SixDOFArmControl__rosidl_typesupport_introspection_c__SixDOFArmControl_init_function,  // function to initialize message memory (memory has to be allocated)
  SixDOFArmControl__rosidl_typesupport_introspection_c__SixDOFArmControl_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SixDOFArmControl__rosidl_typesupport_introspection_c__SixDOFArmControl_message_type_support_handle = {
  0,
  &SixDOFArmControl__rosidl_typesupport_introspection_c__SixDOFArmControl_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_detectabasura
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, detectabasura, msg, SixDOFArmControl)() {
  if (!SixDOFArmControl__rosidl_typesupport_introspection_c__SixDOFArmControl_message_type_support_handle.typesupport_identifier) {
    SixDOFArmControl__rosidl_typesupport_introspection_c__SixDOFArmControl_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SixDOFArmControl__rosidl_typesupport_introspection_c__SixDOFArmControl_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
