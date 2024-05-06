// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from detectabasura:msg/SixDOFArmControl.idl
// generated code does not contain a copyright notice

#ifndef DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__TRAITS_HPP_
#define DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__TRAITS_HPP_

#include "detectabasura/msg/detail/six_dof_arm_control__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<detectabasura::msg::SixDOFArmControl>()
{
  return "detectabasura::msg::SixDOFArmControl";
}

template<>
inline const char * name<detectabasura::msg::SixDOFArmControl>()
{
  return "detectabasura/msg/SixDOFArmControl";
}

template<>
struct has_fixed_size<detectabasura::msg::SixDOFArmControl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<detectabasura::msg::SixDOFArmControl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<detectabasura::msg::SixDOFArmControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__TRAITS_HPP_
