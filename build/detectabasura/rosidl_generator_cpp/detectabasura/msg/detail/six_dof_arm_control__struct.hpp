// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from detectabasura:msg/SixDOFArmControl.idl
// generated code does not contain a copyright notice

#ifndef DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__STRUCT_HPP_
#define DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__detectabasura__msg__SixDOFArmControl __attribute__((deprecated))
#else
# define DEPRECATED__detectabasura__msg__SixDOFArmControl __declspec(deprecated)
#endif

namespace detectabasura
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SixDOFArmControl_
{
  using Type = SixDOFArmControl_<ContainerAllocator>;

  explicit SixDOFArmControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->servo_a_position = 0;
      this->servo_b_position = 0;
      this->servo_c_position = 0;
      this->servo_d_position = 0;
      this->servo_e_position = 0;
      this->servo_f_position = 0;
    }
  }

  explicit SixDOFArmControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->servo_a_position = 0;
      this->servo_b_position = 0;
      this->servo_c_position = 0;
      this->servo_d_position = 0;
      this->servo_e_position = 0;
      this->servo_f_position = 0;
    }
  }

  // field types and members
  using _servo_a_position_type =
    uint8_t;
  _servo_a_position_type servo_a_position;
  using _servo_b_position_type =
    uint8_t;
  _servo_b_position_type servo_b_position;
  using _servo_c_position_type =
    uint8_t;
  _servo_c_position_type servo_c_position;
  using _servo_d_position_type =
    uint8_t;
  _servo_d_position_type servo_d_position;
  using _servo_e_position_type =
    uint8_t;
  _servo_e_position_type servo_e_position;
  using _servo_f_position_type =
    uint8_t;
  _servo_f_position_type servo_f_position;

  // setters for named parameter idiom
  Type & set__servo_a_position(
    const uint8_t & _arg)
  {
    this->servo_a_position = _arg;
    return *this;
  }
  Type & set__servo_b_position(
    const uint8_t & _arg)
  {
    this->servo_b_position = _arg;
    return *this;
  }
  Type & set__servo_c_position(
    const uint8_t & _arg)
  {
    this->servo_c_position = _arg;
    return *this;
  }
  Type & set__servo_d_position(
    const uint8_t & _arg)
  {
    this->servo_d_position = _arg;
    return *this;
  }
  Type & set__servo_e_position(
    const uint8_t & _arg)
  {
    this->servo_e_position = _arg;
    return *this;
  }
  Type & set__servo_f_position(
    const uint8_t & _arg)
  {
    this->servo_f_position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    detectabasura::msg::SixDOFArmControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const detectabasura::msg::SixDOFArmControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<detectabasura::msg::SixDOFArmControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<detectabasura::msg::SixDOFArmControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      detectabasura::msg::SixDOFArmControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<detectabasura::msg::SixDOFArmControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      detectabasura::msg::SixDOFArmControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<detectabasura::msg::SixDOFArmControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<detectabasura::msg::SixDOFArmControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<detectabasura::msg::SixDOFArmControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__detectabasura__msg__SixDOFArmControl
    std::shared_ptr<detectabasura::msg::SixDOFArmControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__detectabasura__msg__SixDOFArmControl
    std::shared_ptr<detectabasura::msg::SixDOFArmControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SixDOFArmControl_ & other) const
  {
    if (this->servo_a_position != other.servo_a_position) {
      return false;
    }
    if (this->servo_b_position != other.servo_b_position) {
      return false;
    }
    if (this->servo_c_position != other.servo_c_position) {
      return false;
    }
    if (this->servo_d_position != other.servo_d_position) {
      return false;
    }
    if (this->servo_e_position != other.servo_e_position) {
      return false;
    }
    if (this->servo_f_position != other.servo_f_position) {
      return false;
    }
    return true;
  }
  bool operator!=(const SixDOFArmControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SixDOFArmControl_

// alias to use template instance with default allocator
using SixDOFArmControl =
  detectabasura::msg::SixDOFArmControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace detectabasura

#endif  // DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__STRUCT_HPP_
