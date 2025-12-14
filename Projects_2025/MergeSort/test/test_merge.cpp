// 第一步：包含必要的头文件
#include <gtest/gtest.h>  // GTest 核心头文件
#include "MergeSort.hpp"  // 业务头文件（CMake已配置src目录，可直接包含）
#include <algorithm>      // 用于对比排序结果（可选）
#include <cstdlib>        // 用于生成随机数组（可选）

// 测试用例1：空数组（边界条件）
TEST(MergeSortTest, EmptyArray) {
    int arr[] = {};
    const int length = 0;
    
    // 调用排序函数（空数组应无崩溃）
    miv::sortings::merge_sort(arr, length);
    
    // 断言：空数组长度仍为0
    ASSERT_EQ(length, 0);
}

// 测试用例2：单元素数组（边界条件）
TEST(MergeSortTest, SingleElementArray) {
    int arr[] = {5};
    const int length = 1;
    int expected[] = {5};
    
    miv::sortings::merge_sort(arr, length);
    
    // 断言：排序后和原数组一致
    ASSERT_EQ(arr[0], expected[0]);
}

// 测试用例3：普通无序数组（核心场景）
TEST(MergeSortTest, NormalUnorderedArray) {
    int arr[] = {3, 7, 6, 9, 0, 12, 4};
    const int length = sizeof(arr) / sizeof(arr[0]);
    // 预期排序结果
    int expected[] = {0, 3, 4, 6, 7, 9, 12};
    
    // 调用排序函数
    miv::sortings::merge_sort(arr, length);
    
    // 逐元素断言（对比排序结果）
    for (int i = 0; i < length; ++i) {
        ASSERT_EQ(arr[i], expected[i])
            << "排序错误：索引" << i << " 实际值=" << arr[i] << " 预期值=" << expected[i];
    }
}

// 测试用例4：已排序数组（反向验证）
TEST(MergeSortTest, AlreadySortedArray) {
    int arr[] = {1, 2, 3, 4, 5};
    const int length = 5;
    int expected[] = {1, 2, 3, 4, 5};
    
    miv::sortings::merge_sort(arr, length);
    
    for (int i = 0; i < length; ++i) {
        ASSERT_EQ(arr[i], expected[i]);
    }
}

// 测试用例5：逆序数组（极端场景）
TEST(MergeSortTest, ReverseSortedArray) {
    int arr[] = {9, 7, 5, 3, 1};
    const int length = 5;
    int expected[] = {1, 3, 5, 7, 9};
    
    miv::sortings::merge_sort(arr, length);
    
    for (int i = 0; i < length; ++i) {
        ASSERT_EQ(arr[i], expected[i]);
    }
}

// 第二步：手动编写main函数（无需链接gtest_main）
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int test_result = RUN_ALL_TESTS(); // 保存测试结果
    
    // ========== 新增：暂停等待按键 ==========
    std::cout << "\n测试完成！按任意键退出...\n";
    std::cin.get(); // 等待用户按回车/任意键
    
    return test_result;
}