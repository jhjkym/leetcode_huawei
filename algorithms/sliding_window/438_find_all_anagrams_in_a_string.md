# 438. 找到字符串中所有字母异位词

- 算法分类：滑动窗口、频次统计。
- 数据结构：两个长度为 26 的数组。
- 对应代码：[438_find_all_anagrams_in_a_string.cpp](./438_find_all_anagrams_in_a_string.cpp)。
- 掌握状态：滑动窗口模板。

## 背诵答案

```cpp
vector<int> findAnagrams(string s, string p) {
    int m = s.size(), n = p.size();
    int left = 0;
    vector<int> ans;
    int cnt[26]{};
    for (char c : p) ++cnt[c - 'a'];
    for (int right = 0; right < m; ++right) {
        char c = s[right];
        --cnt[c - 'a'];
        while (cnt[c - 'a'] < 0) {
            ++cnt[s[left] - 'a'];
            ++left;
        }
        if (right - left + 1 == n) ans.push_back(left);
    }
    return ans;
}
```

`cnt` 记录窗口相对于 `p` 还缺少多少个字符。加入右端字符后，对应计数减一；如果变成负数，说明该字符在窗口中超量，就不断移除左端字符，直到恢复合法。窗口长度等于 `p.size()` 时，窗口和 `p` 的字符频次完全相同，可以记录左端下标。

时间复杂度为 `O(|s| * 26)`，由于字母表大小固定，也可视为 `O(|s|)`；空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/sliding_window/438_find_all_anagrams_in_a_string.cpp -o build/438
./build/438
```
