# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_detectabasura_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED detectabasura_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(detectabasura_FOUND FALSE)
  elseif(NOT detectabasura_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(detectabasura_FOUND FALSE)
  endif()
  return()
endif()
set(_detectabasura_CONFIG_INCLUDED TRUE)

# output package information
if(NOT detectabasura_FIND_QUIETLY)
  message(STATUS "Found detectabasura: 0.0.0 (${detectabasura_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'detectabasura' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${detectabasura_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(detectabasura_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${detectabasura_DIR}/${_extra}")
endforeach()
