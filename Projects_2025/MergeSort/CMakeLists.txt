cmake_minimum_required(VERSION 3.10)
project(MergeSort)

# 关联根目录的 GTest（仅链接，不重复编译）
set(GTEST_DIR ${CMAKE_SOURCE_DIR}/lib/googletest)
if(TARGET gtest AND TARGET gmock)
  include_directories(${GTEST_DIR}/googletest/include)
  include_directories(${GTEST_DIR}/googlemock/include)
elseif(EXISTS ${GTEST_DIR})
  message(WARNING "Google Test exists but not built, skipping tests")
  return()
else()
  message(WARNING "Google Test not found, skipping tests")
  return()
endif()

# 编译业务静态库（src目录）
add_subdirectory(src)

# 编译测试可执行文件（仅保留测试文件，无重复源码）
add_executable(merge_sort_test 
  test/test_merge.cpp
)

# ========== 核心微调：显式指定src为头文件目录（适配hpp回归src） ==========
target_include_directories(merge_sort_test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src  # 编译器优先找src下的hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/test # 若test有头文件则保留，无则删
)

# 链接依赖库（无修改）
target_link_libraries(merge_sort_test PRIVATE 
  merge_sort_lib  # 链接业务库（已包含src下所有cpp）
  gtest           # 链接GTest核心库
  # gtest_main     # 测试文件自己写了main，注释！
)

# 可选：注册测试（让CTest能运行）
add_test(NAME MergeSortTest COMMAND merge_sort_test)