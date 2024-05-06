// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from detectabasura:msg/SixDOFArmControl.idl
// generated code does not contain a copyright notice

#ifndef DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "detectabasura/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "detectabasura/msg/detail/six_dof_arm_control__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace detectabasura
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detectabasura
cdr_serialize(
  const detectabasura::msg::SixDOFArmControl & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detectabasura
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  detectabasura::msg::SixDOFArmControl & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detectabasura
get_serialized_size(
  const detectabasura::msg::SixDOFArmControl & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detectabasura
max_serialized_size_SixDOFArmControl(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace detectabasura

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detectabasura
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, detectabasura, msg, SixDOFArmControl)();

#ifdef __cplusplus
}
#endif

#endif  // DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
