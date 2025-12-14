# 编译业务静态库（包含所有src下的cpp）
add_library(merge_sort_lib
    MergeSort.cpp
    orig_1d_arr.cpp
    io.cpp  # 补充io.cpp
)

# ========== 关键修改：仅暴露src目录，删除对test的反向依赖 ==========
target_include_directories(merge_sort_lib
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}  # 外部模块（test）能直接找到src下的hpp
    # 删掉：PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../test
)