// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from detectabasura:msg/SixDOFArmControl.idl
// generated code does not contain a copyright notice
#include "detectabasura/msg/detail/six_dof_arm_control__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "detectabasura/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "detectabasura/msg/detail/six_dof_arm_control__struct.h"
#include "detectabasura/msg/detail/six_dof_arm_control__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _SixDOFArmControl__ros_msg_type = detectabasura__msg__SixDOFArmControl;

static bool _SixDOFArmControl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SixDOFArmControl__ros_msg_type * ros_message = static_cast<const _SixDOFArmControl__ros_msg_type *>(untyped_ros_message);
  // Field name: servo_a_position
  {
    cdr << ros_message->servo_a_position;
  }

  // Field name: servo_b_position
  {
    cdr << ros_message->servo_b_position;
  }

  // Field name: servo_c_position
  {
    cdr << ros_message->servo_c_position;
  }

  // Field name: servo_d_position
  {
    cdr << ros_message->servo_d_position;
  }

  // Field name: servo_e_position
  {
    cdr << ros_message->servo_e_position;
  }

  // Field name: servo_f_position
  {
    cdr << ros_message->servo_f_position;
  }

  return true;
}

static bool _SixDOFArmControl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SixDOFArmControl__ros_msg_type * ros_message = static_cast<_SixDOFArmControl__ros_msg_type *>(untyped_ros_message);
  // Field name: servo_a_position
  {
    cdr >> ros_message->servo_a_position;
  }

  // Field name: servo_b_position
  {
    cdr >> ros_message->servo_b_position;
  }

  // Field name: servo_c_position
  {
    cdr >> ros_message->servo_c_position;
  }

  // Field name: servo_d_position
  {
    cdr >> ros_message->servo_d_position;
  }

  // Field name: servo_e_position
  {
    cdr >> ros_message->servo_e_position;
  }

  // Field name: servo_f_position
  {
    cdr >> ros_message->servo_f_position;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_detectabasura
size_t get_serialized_size_detectabasura__msg__SixDOFArmControl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SixDOFArmControl__ros_msg_type * ros_message = static_cast<const _SixDOFArmControl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name servo_a_position
  {
    size_t item_size = sizeof(ros_message->servo_a_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name servo_b_position
  {
    size_t item_size = sizeof(ros_message->servo_b_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name servo_c_position
  {
    size_t item_size = sizeof(ros_message->servo_c_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name servo_d_position
  {
    size_t item_size = sizeof(ros_message->servo_d_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name servo_e_position
  {
    size_t item_size = sizeof(ros_message->servo_e_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name servo_f_position
  {
    size_t item_size = sizeof(ros_message->servo_f_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SixDOFArmControl__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_detectabasura__msg__SixDOFArmControl(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_detectabasura
size_t max_serialized_size_detectabasura__msg__SixDOFArmControl(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: servo_a_position
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: servo_b_position
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: servo_c_position
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: servo_d_position
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: servo_e_position
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: servo_f_position
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _SixDOFArmControl__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_detectabasura__msg__SixDOFArmControl(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_SixDOFArmControl = {
  "detectabasura::msg",
  "SixDOFArmControl",
  _SixDOFArmControl__cdr_serialize,
  _SixDOFArmControl__cdr_deserialize,
  _SixDOFArmControl__get_serialized_size,
  _SixDOFArmControl__max_serialized_size
};

static rosidl_message_type_support_t _SixDOFArmControl__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SixDOFArmControl,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, detectabasura, msg, SixDOFArmControl)() {
  return &_SixDOFArmControl__type_support;
}

#if defined(__cplusplus)
}
#endif
