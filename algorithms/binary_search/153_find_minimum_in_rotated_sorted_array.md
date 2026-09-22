# 153. 寻找旋转排序数组中的最小值

- 算法分类：二分查找、旋转数组。
- 数据结构：数组。
- 对应代码：[153_find_minimum_in_rotated_sorted_array.cpp](./153_find_minimum_in_rotated_sorted_array.cpp)。
- 掌握状态：旋转数组最小值模板。

## 背诵答案

```cpp
int findMin(vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}
```

## 背诵口诀

> 中间大于右端，最小值在右边；
> 否则最小值在左边，包含中间。

比较 `nums[mid]` 与 `nums[right]`：

- `nums[mid] > nums[right]`：`mid` 位于旋转前较大的那一段，最小值一定在 `mid` 右侧，所以 `left = mid + 1`；
- `nums[mid] < nums[right]`：`mid` 位于包含最小值的升序段，`mid` 自身可能就是最小值，所以 `right = mid`。

循环结束时 `left == right`，搜索区间只剩一个元素，它就是最小值。

## 易错点

- 应与 `nums[right]` 比较，而不是固定与数组最后一个元素比较。
- 右边界更新为 `right = mid`，因为 `mid` 可能就是答案。
- 左边界更新为 `left = mid + 1`，因为此时 `mid` 一定不是答案。
- 题目保证元素互不相同，所以不会出现 `nums[mid] == nums[right]` 且区间长度大于一的情况。

时间复杂度为 `O(log n)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/binary_search/153_find_minimum_in_rotated_sorted_array.cpp -o build/153
./build/153
```
