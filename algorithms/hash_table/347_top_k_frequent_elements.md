# 347. 前 K 个高频元素

- 算法分类：哈希计数、桶排序。
- 数据结构：`unordered_map`、二维桶数组。
- 对应代码：[347_top_k_frequent_elements.cpp](./347_top_k_frequent_elements.cpp)。
- 掌握状态：频率桶模板。

## 背诵答案

```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequency;
    for (int num : nums) frequency[num]++;

    int n = nums.size();
    vector<vector<int>> buckets(n + 1);
    for (const auto& [num, count] : frequency) {
        buckets[count].push_back(num);
    }

    vector<int> ans;
    for (int count = n; count >= 1 && k > 0; count--) {
        for (int num : buckets[count]) {
            ans.push_back(num);
            k--;
            if (k == 0) break;
        }
    }
    return ans;
}
```

## 背诵口诀

> 哈希表统计次数；
> 次数作为桶下标；
> 从高频桶向低频桶取 `k` 个。

一个数字最多出现 `n` 次，所以创建 `n + 1` 个桶：

```cpp
buckets[count].push_back(num);
```

其中 `buckets[count]` 保存所有出现次数为 `count` 的数字。从下标 `n` 向 `1` 遍历，就能按照频率从高到低收集答案。

## 易错点

- 桶的大小是 `n + 1`，因为最大频率可能等于 `n`。
- 桶下标是频率，桶中保存的是数字。
- 同一频率可能有多个数字，所以每个桶是一个数组。
- 题目保证答案唯一，但不要求返回顺序。
- 每收集一个数字就执行 `k--`，减到 `0` 时停止。

统计、装桶和遍历桶都是线性操作，平均时间复杂度为 `O(n)`，空间复杂度为 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/hash_table/347_top_k_frequent_elements.cpp -o build/347
./build/347
```
