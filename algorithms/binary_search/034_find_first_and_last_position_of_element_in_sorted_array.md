# 34. 在排序数组中查找元素的第一个和最后一个位置

- 算法分类：二分查找、左右边界。
- 数据结构：升序数组。
- 对应代码：[034_find_first_and_last_position_of_element_in_sorted_array.cpp](./034_find_first_and_last_position_of_element_in_sorted_array.cpp)。
- 掌握状态：两次左边界二分模板。

## 背诵答案

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = lowerBound(nums, target);
        if (first == n || nums[first] != target) return {-1, -1};

        int last = lowerBound(nums, target + 1) - 1;
        return {first, last};
    }

private:
    int lowerBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
```

## 背诵口诀

> 第一次找 `target` 的左边界；
> 第二次找 `target + 1` 的左边界，再减一。

`lowerBound(nums, x)` 返回第一个大于等于 `x` 的位置。因此：

```cpp
first = lowerBound(nums, target);
last = lowerBound(nums, target + 1) - 1;
```

第一个位置如果越界或值不等于 `target`，说明目标不存在，直接返回 `{-1, -1}`。

## 易错点

- 必须先判断 `first == nums.size()`，再访问 `nums[first]`。
- 最后一个位置要减一。
- `lowerBound` 使用左闭右开区间 `[left, right)`，与第 35 题完全相同。
- 题目约束保证 `target <= 10^9`，因此 `target + 1` 不会溢出 `int`。

执行两次二分查找，时间复杂度为 `O(log n)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/binary_search/034_find_first_and_last_position_of_element_in_sorted_array.cpp -o build/034
./build/034
```
