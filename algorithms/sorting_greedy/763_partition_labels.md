# 763. 划分字母区间

- 算法分类：贪心、区间划分。
- 数据结构：字符最后位置数组。
- 对应代码：[763_partition_labels.cpp](./763_partition_labels.cpp)。
- 掌握状态：最远边界贪心模板。

## 背诵答案

```cpp
vector<int> partitionLabels(string s) {
    int last[26]{};
    int n = s.size();
    for (int i = 0; i < n; ++i) last[s[i] - 'a'] = i;

    vector<int> ans;
    int start = 0;
    int end = 0;

    for (int i = 0; i < n; ++i) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) {
            ans.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return ans;
}
```

## 背诵口诀

> 先记录每个字母最后位置；
> 扫描时不断扩展最远边界；
> 走到边界就切一段。

扫描当前区间时，只要遇到一个字符，就必须保证该字符的最后一次出现也包含在当前区间内：

```cpp
end = max(end, last[s[i] - 'a']);
```

当 `i == end` 时，当前区间内出现过的所有字符都不会再出现在后面，因此可以安全划分，并且这是能得到最多区间的最早切割位置。

## 易错点

- 第一遍必须记录每个字符最后一次出现的位置。
- `end` 要取当前边界和字符最后位置的最大值。
- 区间长度是 `end - start + 1`。
- 切割后，下一段起点是 `i + 1`。
- 题目只包含小写英文字母，因此可以使用长度为 `26` 的数组。

两次线性扫描，时间复杂度为 `O(n)`；字符表大小固定，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/sorting_greedy/763_partition_labels.cpp -o build/763
./build/763
```
