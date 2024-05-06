// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from detectabasura:msg/SixDOFArmControl.idl
// generated code does not contain a copyright notice

#ifndef DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__STRUCT_H_
#define DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/SixDOFArmControl in the package detectabasura.
typedef struct detectabasura__msg__SixDOFArmControl
{
  uint8_t servo_a_position;
  uint8_t servo_b_position;
  uint8_t servo_c_position;
  uint8_t servo_d_position;
  uint8_t servo_e_position;
  uint8_t servo_f_position;
} detectabasura__msg__SixDOFArmControl;

// Struct for a sequence of detectabasura__msg__SixDOFArmControl.
typedef struct detectabasura__msg__SixDOFArmControl__Sequence
{
  detectabasura__msg__SixDOFArmControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} detectabasura__msg__SixDOFArmControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__STRUCT_H_
