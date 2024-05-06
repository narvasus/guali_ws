// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from detectabasura:msg/SixDOFArmControl.idl
// generated code does not contain a copyright notice

#ifndef DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__FUNCTIONS_H_
#define DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "detectabasura/msg/rosidl_generator_c__visibility_control.h"

#include "detectabasura/msg/detail/six_dof_arm_control__struct.h"

/// Initialize msg/SixDOFArmControl message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * detectabasura__msg__SixDOFArmControl
 * )) before or use
 * detectabasura__msg__SixDOFArmControl__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_detectabasura
bool
detectabasura__msg__SixDOFArmControl__init(detectabasura__msg__SixDOFArmControl * msg);

/// Finalize msg/SixDOFArmControl message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detectabasura
void
detectabasura__msg__SixDOFArmControl__fini(detectabasura__msg__SixDOFArmControl * msg);

/// Create msg/SixDOFArmControl message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * detectabasura__msg__SixDOFArmControl__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_detectabasura
detectabasura__msg__SixDOFArmControl *
detectabasura__msg__SixDOFArmControl__create();

/// Destroy msg/SixDOFArmControl message.
/**
 * It calls
 * detectabasura__msg__SixDOFArmControl__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detectabasura
void
detectabasura__msg__SixDOFArmControl__destroy(detectabasura__msg__SixDOFArmControl * msg);

/// Check for msg/SixDOFArmControl message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_detectabasura
bool
detectabasura__msg__SixDOFArmControl__are_equal(const detectabasura__msg__SixDOFArmControl * lhs, const detectabasura__msg__SixDOFArmControl * rhs);

/// Copy a msg/SixDOFArmControl message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_detectabasura
bool
detectabasura__msg__SixDOFArmControl__copy(
  const detectabasura__msg__SixDOFArmControl * input,
  detectabasura__msg__SixDOFArmControl * output);

/// Initialize array of msg/SixDOFArmControl messages.
/**
 * It allocates the memory for the number of elements and calls
 * detectabasura__msg__SixDOFArmControl__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_detectabasura
bool
detectabasura__msg__SixDOFArmControl__Sequence__init(detectabasura__msg__SixDOFArmControl__Sequence * array, size_t size);

/// Finalize array of msg/SixDOFArmControl messages.
/**
 * It calls
 * detectabasura__msg__SixDOFArmControl__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detectabasura
void
detectabasura__msg__SixDOFArmControl__Sequence__fini(detectabasura__msg__SixDOFArmControl__Sequence * array);

/// Create array of msg/SixDOFArmControl messages.
/**
 * It allocates the memory for the array and calls
 * detectabasura__msg__SixDOFArmControl__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_detectabasura
detectabasura__msg__SixDOFArmControl__Sequence *
detectabasura__msg__SixDOFArmControl__Sequence__create(size_t size);

/// Destroy array of msg/SixDOFArmControl messages.
/**
 * It calls
 * detectabasura__msg__SixDOFArmControl__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detectabasura
void
detectabasura__msg__SixDOFArmControl__Sequence__destroy(detectabasura__msg__SixDOFArmControl__Sequence * array);

/// Check for msg/SixDOFArmControl message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_detectabasura
bool
detectabasura__msg__SixDOFArmControl__Sequence__are_equal(const detectabasura__msg__SixDOFArmControl__Sequence * lhs, const detectabasura__msg__SixDOFArmControl__Sequence * rhs);

/// Copy an array of msg/SixDOFArmControl messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_detectabasura
bool
detectabasura__msg__SixDOFArmControl__Sequence__copy(
  const detectabasura__msg__SixDOFArmControl__Sequence * input,
  detectabasura__msg__SixDOFArmControl__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__FUNCTIONS_H_
