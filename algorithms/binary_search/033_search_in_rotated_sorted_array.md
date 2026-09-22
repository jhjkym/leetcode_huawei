# 33. 搜索旋转排序数组

- 算法分类：二分查找、旋转数组。
- 数据结构：数组。
- 对应代码：[033_search_in_rotated_sorted_array.cpp](./033_search_in_rotated_sorted_array.cpp)。
- 掌握状态：旋转数组二分模板。

## 背诵答案

```cpp
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;

        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}
```

## 背诵口诀

> 每轮必有一半有序；
> 先找有序的一半；
> 目标在有序区间就保留，否则去另一半。

判断左半部分是否有序：

```cpp
nums[left] <= nums[mid]
```

如果左半有序，再判断目标是否位于左闭右开区间：

```cpp
nums[left] <= target && target < nums[mid]
```

否则右半一定有序，判断目标是否位于：

```cpp
nums[mid] < target && target <= nums[right]
```

## 易错点

- 先检查 `nums[mid] == target`，再判断哪一半有序。
- 判断左半有序时使用 `<=`，这样单元素区间也能正确处理。
- 左侧目标区间是 `[nums[left], nums[mid])`。
- 右侧目标区间是 `(nums[mid], nums[right]]`。
- 题目保证数组元素互不相同，因此不需要处理重复值导致的边界模糊。

时间复杂度为 `O(log n)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/binary_search/033_search_in_rotated_sorted_array.cpp -o build/033
./build/033
```
