# 输入变量:
# 输入phg_PATH, THIRDLIB_PATH, 
# 依据这两个输入路径搜索需要的头文件和库文件,
#
# 输出变量:
# 输出phg_FOUND, phg_INCLUDES, phg_LIBRARIES.
# 并将phg_INCLUDES追加到THIRDLIB_INCLUDES,
# 将phg_LIBRARIES追加到THIRDLIB_LIBRARIES


# phg缺省路径
if (NOT phg_PATH)
  set(phg_PATH ${CMAKE_CURRENT_LIST_DIR}/..)
endif ()

# 定义搜索路径
set(phg_search_PATHS ${phg_PATH})
foreach (path ${THIRDLIB_PATH})
  list(APPEND phg_search_PATHS ${path}/phg)
endforeach()

# 这个模块由很多的库文件组成
if (NOT phg_FIND_COMPONENTS)
  set(phg_FIND_COMPONENTS phg)
endif ()

# 设置搜索路径
set(_OLD_PREFIX_PATH ${CMAKE_PREFIX_PATH})
set(CMAKE_PREFIX_PATH ${phg_search_PATHS})
if (NOT THIRDLIB_FIND_ARGUMENTS)
  set(THIRDLIB_FIND_ARGUMENTS "PATHS ${phg_search_PATHS} PATH_SUFFIXES lib NO_DEFAULT_PATH")
endif ()

# 搜索需要的头文件
find_file(phg_INCLUDES NAMES include ${THIRDLIB_FIND_ARGUMENTS})
if (phg_INCLUDES)
  # do nothing
elseif (phg_FIND_REQUIRED)
  message(FATAL_ERROR "Not found 'include' directory in ${phg_search_PATHS}")
endif ()

# 搜索需要的库文件
foreach (module ${phg_FIND_COMPONENTS})
  find_library(phg_LIBRARIES_${module} NAMES ${module} ${THIRDLIB_FIND_ARGUMENTS})
  if (phg_LIBRARIES_${module})
    list(APPEND phg_LIBRARIES ${phg_LIBRARIES_${module}})
  else ()
    list(APPEND phg_NO_LIBRARIES ${phg_LIBRARIES_${module}})
    if (phg_FIND_REQUIRED)
      message(FATAL_ERROR "Not found lib/'${module}' in ${phg_search_PATHS}")
    endif ()
  endif ()
endforeach ()

# 恢复CMAKE_PREFIX_PATH
set(CMAKE_PREFIX_PATH ${_OLD_PREFIX_PATH})

# 输出信息
if (NOT phg_FIND_QUIETLY)
  message(STATUS "Found phg: ${phg_INCLUDES}, ${phg_LIBRARIES};${phg_NO_LIBRARIES} in ${phg_search_PATHS}")
endif ()

# 定义输出变量
if (phg_INCLUDES AND phg_LIBRARIES)
  set(phg_FOUND TRUE)
  string(TOUPPER phg _UPPER_CASE)
  set(HAVE_${_UPPER_CASE} 1)
  unset(_UPPER_CASE)
else ()
  set(phg_FOUND FALSE)
endif ()

# 只是为了方便, 其实破坏了封装
# 追加包含变量到THIRDLIB变量里面
if (phg_INCLUDES)
  list(APPEND THIRDLIB_INCLUDES ${phg_INCLUDES})
endif ()
# 追加库文件变量到THIRDLIB变量里面, 只是为了方便, 其实破坏了封装
if (phg_LIBRARIES)
  list(APPEND THIRDLIB_LIBRARIES ${phg_LIBRARIES})
endif ()

# phg依赖的三方库，放到最后
#include (${CMAKE_CURRENT_LIST_DIR}/Thirdparty.cmake)
set(THIRDLIB_INCLUDES ${CMAKE_CURRENT_LIST_DIR}/../include)
set(THIRDLIB_LIBRARIES ${CMAKE_CURRENT_LIST_DIR}/../lib/msmpi.lib)
add_definitions(/EHsc /FS -D_USE_MATH_DEFINES -D_CRT_SECURE_NO_WARNINGS)

set(phg_THIRDLIB_INCLUDES ${THIRDLIB_INCLUDES})
set(phg_THIRDLIB_LIBRARIES ${THIRDLIB_LIBRARIES})

# 辅助宏，用于快速实现phg的应用程序
macro(add_phg_executable)
  set(_TARGET ${ARGV0})
  add_executable(${ARGV})
  include_directories(${phg_INCLUDES} ${phg_THIRDLIB_INCLUDES})
  target_link_libraries(${_TARGET} ${phg_LIBRARIES} ${phg_THIRDLIB_LIBRARIES})
  if (UNIX)
    set_target_properties(${_TARGET} PROPERTIES
      LINK_FLAGS "-Wl,--as-needed,-z,defs"
      )
  endif ()
  unset(_TARGET)
endmacro ()



