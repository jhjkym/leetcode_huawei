# 22. 括号生成

- 算法分类：回溯、剪枝。
- 数据结构：路径字符串、递归栈。
- 对应代码：[022_generate_parentheses.cpp](./022_generate_parentheses.cpp)。
- 掌握状态：括号回溯模板。

## 背诵答案

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        backtrack(n, 0, 0, path, ans);
        return ans;
    }

private:
    void backtrack(int n, int left, int right, string& path,
                   vector<string>& ans) {
        if (left == n && right == n) {
            ans.push_back(path);
            return;
        }

        if (left < n) {
            path.push_back('(');
            backtrack(n, left + 1, right, path, ans);
            path.pop_back();
        }

        if (right < left) {
            path.push_back(')');
            backtrack(n, left, right + 1, path, ans);
            path.pop_back();
        }
    }
};
```

## 背诵口诀

> 左括号没用完就能放；
> 右括号比左括号少才能放；
> 左右都用完就收集。

`left` 和 `right` 分别表示已经使用的左右括号数量。

- `left < n`：还有左括号可以使用；
- `right < left`：当前未匹配的左括号至少有一个，可以安全添加右括号；
- `left == n && right == n`：生成了一个完整合法答案。

这两个选择条件会直接阻止非法括号字符串进入搜索树，因此不需要生成后再检查合法性。

## 易错点

- 添加右括号的条件是 `right < left`，不能写成 `right < n`。
- 左右两个分支都是独立的 `if`，不是 `if...else`。
- 每次递归返回后都要 `pop_back()` 撤销选择。
- 收集答案后立即返回。

答案数量是第 `n` 个卡特兰数。时间复杂度与所有答案的总长度成正比，常写作 `O(Cn * n)`；递归栈空间复杂度为 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/backtracking/022_generate_parentheses.cpp -o build/022
./build/022
```
