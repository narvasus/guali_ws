// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from detectabasura:msg/SixDOFArmControl.idl
// generated code does not contain a copyright notice

#ifndef DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__TRAITS_HPP_
#define DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__TRAITS_HPP_

#include "detectabasura/msg/detail/six_dof_arm_control__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const detectabasura::msg::SixDOFArmControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: servo_a_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "servo_a_position: ";
    value_to_yaml(msg.servo_a_position, out);
    out << "\n";
  }

  // member: servo_b_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "servo_b_position: ";
    value_to_yaml(msg.servo_b_position, out);
    out << "\n";
  }

  // member: servo_c_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "servo_c_position: ";
    value_to_yaml(msg.servo_c_position, out);
    out << "\n";
  }

  // member: servo_d_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "servo_d_position: ";
    value_to_yaml(msg.servo_d_position, out);
    out << "\n";
  }

  // member: servo_e_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "servo_e_position: ";
    value_to_yaml(msg.servo_e_position, out);
    out << "\n";
  }

  // member: servo_f_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "servo_f_position: ";
    value_to_yaml(msg.servo_f_position, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const detectabasura::msg::SixDOFArmControl & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

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
