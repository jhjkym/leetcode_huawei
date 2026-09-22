# 131. 分割回文串

- 算法分类：回溯、双指针判断回文。
- 数据结构：路径数组、递归栈。
- 对应代码：[131_palindrome_partitioning.cpp](./131_palindrome_partitioning.cpp)。
- 掌握状态：字符串切割回溯模板。

## 背诵答案

```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        backtrack(s, 0, path, ans);
        return ans;
    }

private:
    void backtrack(const string& s, int start, vector<string>& path,
                   vector<vector<string>>& ans) {
        int n = s.size();
        if (start == n) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < n; ++end) {
            if (!isPalindrome(s, start, end)) continue;

            path.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, path, ans);
            path.pop_back();
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
```

## 背诵口诀

> `start` 是本段起点，`end` 枚举本段终点；
> 是回文才选择，下一段从 `end + 1` 开始；
> 到达字符串末尾就收集。

当前选择的子串是闭区间 `[start, end]`：

```cpp
s.substr(start, end - start + 1)
```

选择当前回文子串后，下一段从 `end + 1` 开始。递归返回后撤销选择，继续尝试更长的当前子串。

## 易错点

- `substr` 的第二个参数是长度，因此是 `end - start + 1`。
- 当前子串不是回文时直接 `continue`。
- 下一层起点是 `end + 1`，不是 `start + 1`。
- `start == s.size()` 表示整个字符串已经成功分割，此时收集路径。
- 判断回文时左右指针向中间移动。

回溯搜索的方案数是指数级，最坏时间复杂度为 `O(n * 2^n)`；路径和递归栈空间复杂度为 `O(n)`，不计算答案空间。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/backtracking/131_palindrome_partitioning.cpp -o build/131
./build/131
```
