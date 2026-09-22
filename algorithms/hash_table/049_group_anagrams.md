# 49. 字母异位词分组

- 算法分类：哈希表、排序。
- 数据结构：`unordered_map<string, vector<string>>`。
- 对应代码：[049_group_anagrams.cpp](./049_group_anagrams.cpp)。
- 掌握状态：常见哈希表模板。

## 背诵答案

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (string word : strs) {
        string key = word;
        sort(key.begin(), key.end());
        groups[key].push_back(word);
    }

    vector<vector<string>> result;
    for (auto& [key, words] : groups) {
        result.push_back(words);
    }
    return result;
}
```

字母异位词包含完全相同的字母，只是顺序不同。例如 `eat`、`tea`、`ate` 排序后都变成 `aet`，所以把排序后的字符串作为 key，就能把它们放进同一个分组。

题目不要求分组顺序，因此哈希表遍历出来的顺序可以任意。

设单词数量为 `n`，平均单词长度为 `k`，时间复杂度为 `O(n × k log k)`，空间复杂度为 `O(n × k)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/hash_table/049_group_anagrams.cpp -o build/049
./build/049
```
