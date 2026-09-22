# 4. 寻找两个正序数组的中位数

- 算法分类：二分查找、数组分割。
- 数据结构：两个升序数组。
- 对应代码：[004_median_of_two_sorted_arrays.cpp](./004_median_of_two_sorted_arrays.cpp)。
- 掌握状态：困难二分分割模板。

## 背诵答案

```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size(), n = nums2.size();
    int left = 0, right = m;

    while (left <= right) {
        int i = left + (right - left) / 2;
        int j = (m + n + 1) / 2 - i;

        long long left1 = i == 0 ? LLONG_MIN : nums1[i - 1];
        long long right1 = i == m ? LLONG_MAX : nums1[i];
        long long left2 = j == 0 ? LLONG_MIN : nums2[j - 1];
        long long right2 = j == n ? LLONG_MAX : nums2[j];

        if (left1 <= right2 && left2 <= right1) {
            long long leftMax = max(left1, left2);
            if ((m + n) % 2 == 1) return leftMax;

            long long rightMin = min(right1, right2);
            return (leftMax + rightMin) / 2.0;
        }

        if (left1 > right2) right = i - 1;
        else left = i + 1;
    }
    return 0.0;
}
```

## 背诵口诀

> 短数组上二分；
> 左边数量固定，`j` 由 `i` 推出；
> 交叉比较，左边都不大于右边；
> 奇数取左边最大，偶数再和右边最小求平均。

## 四个边界值

数组分别在 `i` 和 `j` 处分割：

```text
nums1: ... left1 | right1 ...
nums2: ... left2 | right2 ...
```

左半部分比右半部分最多多一个元素，所以：

```cpp
j = (m + n + 1) / 2 - i;
```

正确分割需要满足交叉关系：

```cpp
left1 <= right2 && left2 <= right1
```

分割位于数组边缘时，用无穷小或无穷大作为哨兵。

## 如何移动二分边界

- `left1 > right2`：第一个数组左边取多了，令 `right = i - 1`；
- 否则说明第一个数组左边取少了，令 `left = i + 1`。

## 易错点

- 必须保证 `nums1` 是较短数组，否则 `j` 可能越界。
- 左半部分数量使用 `(m + n + 1) / 2`，这个 `+1` 可以统一奇偶情况。
- 正确分割要同时检查两个交叉条件。
- 偶数长度时使用 `long long` 保存两侧值，避免求和溢出。
- 题目保证两个数组不会同时为空。

二分发生在较短数组上，时间复杂度为 `O(log(min(m,n)))`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/binary_search/004_median_of_two_sorted_arrays.cpp -o build/004
./build/004
```
