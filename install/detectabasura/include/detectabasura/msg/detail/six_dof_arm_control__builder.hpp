// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from detectabasura:msg/SixDOFArmControl.idl
// generated code does not contain a copyright notice

#ifndef DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__BUILDER_HPP_
#define DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__BUILDER_HPP_

#include "detectabasura/msg/detail/six_dof_arm_control__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace detectabasura
{

namespace msg
{

namespace builder
{

class Init_SixDOFArmControl_servo_f_position
{
public:
  explicit Init_SixDOFArmControl_servo_f_position(::detectabasura::msg::SixDOFArmControl & msg)
  : msg_(msg)
  {}
  ::detectabasura::msg::SixDOFArmControl servo_f_position(::detectabasura::msg::SixDOFArmControl::_servo_f_position_type arg)
  {
    msg_.servo_f_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::detectabasura::msg::SixDOFArmControl msg_;
};

class Init_SixDOFArmControl_servo_e_position
{
public:
  explicit Init_SixDOFArmControl_servo_e_position(::detectabasura::msg::SixDOFArmControl & msg)
  : msg_(msg)
  {}
  Init_SixDOFArmControl_servo_f_position servo_e_position(::detectabasura::msg::SixDOFArmControl::_servo_e_position_type arg)
  {
    msg_.servo_e_position = std::move(arg);
    return Init_SixDOFArmControl_servo_f_position(msg_);
  }

private:
  ::detectabasura::msg::SixDOFArmControl msg_;
};

class Init_SixDOFArmControl_servo_d_position
{
public:
  explicit Init_SixDOFArmControl_servo_d_position(::detectabasura::msg::SixDOFArmControl & msg)
  : msg_(msg)
  {}
  Init_SixDOFArmControl_servo_e_position servo_d_position(::detectabasura::msg::SixDOFArmControl::_servo_d_position_type arg)
  {
    msg_.servo_d_position = std::move(arg);
    return Init_SixDOFArmControl_servo_e_position(msg_);
  }

private:
  ::detectabasura::msg::SixDOFArmControl msg_;
};

class Init_SixDOFArmControl_servo_c_position
{
public:
  explicit Init_SixDOFArmControl_servo_c_position(::detectabasura::msg::SixDOFArmControl & msg)
  : msg_(msg)
  {}
  Init_SixDOFArmControl_servo_d_position servo_c_position(::detectabasura::msg::SixDOFArmControl::_servo_c_position_type arg)
  {
    msg_.servo_c_position = std::move(arg);
    return Init_SixDOFArmControl_servo_d_position(msg_);
  }

private:
  ::detectabasura::msg::SixDOFArmControl msg_;
};

class Init_SixDOFArmControl_servo_b_position
{
public:
  explicit Init_SixDOFArmControl_servo_b_position(::detectabasura::msg::SixDOFArmControl & msg)
  : msg_(msg)
  {}
  Init_SixDOFArmControl_servo_c_position servo_b_position(::detectabasura::msg::SixDOFArmControl::_servo_b_position_type arg)
  {
    msg_.servo_b_position = std::move(arg);
    return Init_SixDOFArmControl_servo_c_position(msg_);
  }

private:
  ::detectabasura::msg::SixDOFArmControl msg_;
};

class Init_SixDOFArmControl_servo_a_position
{
public:
  Init_SixDOFArmControl_servo_a_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SixDOFArmControl_servo_b_position servo_a_position(::detectabasura::msg::SixDOFArmControl::_servo_a_position_type arg)
  {
    msg_.servo_a_position = std::move(arg);
    return Init_SixDOFArmControl_servo_b_position(msg_);
  }

private:
  ::detectabasura::msg::SixDOFArmControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::detectabasura::msg::SixDOFArmControl>()
{
  return detectabasura::msg::builder::Init_SixDOFArmControl_servo_a_position();
}

}  // namespace detectabasura

#endif  // DETECTABASURA__MSG__DETAIL__SIX_DOF_ARM_CONTROL__BUILDER_HPP_
