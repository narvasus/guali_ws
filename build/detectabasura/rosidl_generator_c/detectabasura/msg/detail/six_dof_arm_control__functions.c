// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from detectabasura:msg/SixDOFArmControl.idl
// generated code does not contain a copyright notice
#include "detectabasura/msg/detail/six_dof_arm_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
detectabasura__msg__SixDOFArmControl__init(detectabasura__msg__SixDOFArmControl * msg)
{
  if (!msg) {
    return false;
  }
  // servo_a_position
  // servo_b_position
  // servo_c_position
  // servo_d_position
  // servo_e_position
  // servo_f_position
  return true;
}

void
detectabasura__msg__SixDOFArmControl__fini(detectabasura__msg__SixDOFArmControl * msg)
{
  if (!msg) {
    return;
  }
  // servo_a_position
  // servo_b_position
  // servo_c_position
  // servo_d_position
  // servo_e_position
  // servo_f_position
}

bool
detectabasura__msg__SixDOFArmControl__are_equal(const detectabasura__msg__SixDOFArmControl * lhs, const detectabasura__msg__SixDOFArmControl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // servo_a_position
  if (lhs->servo_a_position != rhs->servo_a_position) {
    return false;
  }
  // servo_b_position
  if (lhs->servo_b_position != rhs->servo_b_position) {
    return false;
  }
  // servo_c_position
  if (lhs->servo_c_position != rhs->servo_c_position) {
    return false;
  }
  // servo_d_position
  if (lhs->servo_d_position != rhs->servo_d_position) {
    return false;
  }
  // servo_e_position
  if (lhs->servo_e_position != rhs->servo_e_position) {
    return false;
  }
  // servo_f_position
  if (lhs->servo_f_position != rhs->servo_f_position) {
    return false;
  }
  return true;
}

bool
detectabasura__msg__SixDOFArmControl__copy(
  const detectabasura__msg__SixDOFArmControl * input,
  detectabasura__msg__SixDOFArmControl * output)
{
  if (!input || !output) {
    return false;
  }
  // servo_a_position
  output->servo_a_position = input->servo_a_position;
  // servo_b_position
  output->servo_b_position = input->servo_b_position;
  // servo_c_position
  output->servo_c_position = input->servo_c_position;
  // servo_d_position
  output->servo_d_position = input->servo_d_position;
  // servo_e_position
  output->servo_e_position = input->servo_e_position;
  // servo_f_position
  output->servo_f_position = input->servo_f_position;
  return true;
}

detectabasura__msg__SixDOFArmControl *
detectabasura__msg__SixDOFArmControl__create()
{
  detectabasura__msg__SixDOFArmControl * msg = (detectabasura__msg__SixDOFArmControl *)malloc(sizeof(detectabasura__msg__SixDOFArmControl));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(detectabasura__msg__SixDOFArmControl));
  bool success = detectabasura__msg__SixDOFArmControl__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
detectabasura__msg__SixDOFArmControl__destroy(detectabasura__msg__SixDOFArmControl * msg)
{
  if (msg) {
    detectabasura__msg__SixDOFArmControl__fini(msg);
  }
  free(msg);
}


bool
detectabasura__msg__SixDOFArmControl__Sequence__init(detectabasura__msg__SixDOFArmControl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  detectabasura__msg__SixDOFArmControl * data = NULL;
  if (size) {
    data = (detectabasura__msg__SixDOFArmControl *)calloc(size, sizeof(detectabasura__msg__SixDOFArmControl));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = detectabasura__msg__SixDOFArmControl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        detectabasura__msg__SixDOFArmControl__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
detectabasura__msg__SixDOFArmControl__Sequence__fini(detectabasura__msg__SixDOFArmControl__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      detectabasura__msg__SixDOFArmControl__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

detectabasura__msg__SixDOFArmControl__Sequence *
detectabasura__msg__SixDOFArmControl__Sequence__create(size_t size)
{
  detectabasura__msg__SixDOFArmControl__Sequence * array = (detectabasura__msg__SixDOFArmControl__Sequence *)malloc(sizeof(detectabasura__msg__SixDOFArmControl__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = detectabasura__msg__SixDOFArmControl__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
detectabasura__msg__SixDOFArmControl__Sequence__destroy(detectabasura__msg__SixDOFArmControl__Sequence * array)
{
  if (array) {
    detectabasura__msg__SixDOFArmControl__Sequence__fini(array);
  }
  free(array);
}

bool
detectabasura__msg__SixDOFArmControl__Sequence__are_equal(const detectabasura__msg__SixDOFArmControl__Sequence * lhs, const detectabasura__msg__SixDOFArmControl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!detectabasura__msg__SixDOFArmControl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
detectabasura__msg__SixDOFArmControl__Sequence__copy(
  const detectabasura__msg__SixDOFArmControl__Sequence * input,
  detectabasura__msg__SixDOFArmControl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(detectabasura__msg__SixDOFArmControl);
    detectabasura__msg__SixDOFArmControl * data =
      (detectabasura__msg__SixDOFArmControl *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!detectabasura__msg__SixDOFArmControl__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          detectabasura__msg__SixDOFArmControl__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!detectabasura__msg__SixDOFArmControl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
