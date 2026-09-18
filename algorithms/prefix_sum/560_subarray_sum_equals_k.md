# 560. 和为 K 的子数组

- 算法分类：前缀和、哈希表。
- 数据结构：`unordered_map<int, int>`。
- 对应代码：[560_subarray_sum_equals_k.cpp](./560_subarray_sum_equals_k.cpp)。
- 掌握状态：前缀和模板。

## 背诵答案

```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    count[0] = 1;
    int prefix = 0, answer = 0;
    for (int x : nums) {
        prefix += x;
        answer += count[prefix - k];
        ++count[prefix];
    }
    return answer;
}
```

设当前前缀和为 `prefix`。如果之前某个位置的前缀和是 `prefix - k`，两者之间的连续子数组和就是 `k`。哈希表记录每种前缀和出现的次数，因此同一个前缀和出现多次时要全部计入。

`count[0] = 1` 表示空前缀，能够统计从数组第一个元素开始的符合条件的子数组。数组可以包含负数，所以不能使用只适用于非负数的普通滑动窗口。

时间复杂度 `O(n)`，空间复杂度 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/prefix_sum/560_subarray_sum_equals_k.cpp -o build/560
./build/560
```
