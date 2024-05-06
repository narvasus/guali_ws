// generated from rosidl_generator_cpp/resource/rosidl_generator_cpp__visibility_control.hpp.in
// generated code does not contain a copyright notice

#ifndef DETECTABASURA__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
#define DETECTABASURA__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_CPP_EXPORT_detectabasura __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_CPP_IMPORT_detectabasura __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_CPP_EXPORT_detectabasura __declspec(dllexport)
    #define ROSIDL_GENERATOR_CPP_IMPORT_detectabasura __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_CPP_BUILDING_DLL_detectabasura
    #define ROSIDL_GENERATOR_CPP_PUBLIC_detectabasura ROSIDL_GENERATOR_CPP_EXPORT_detectabasura
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_detectabasura ROSIDL_GENERATOR_CPP_IMPORT_detectabasura
  #endif
#else
  #define ROSIDL_GENERATOR_CPP_EXPORT_detectabasura __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_CPP_IMPORT_detectabasura
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_CPP_PUBLIC_detectabasura __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_detectabasura
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // DETECTABASURA__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
