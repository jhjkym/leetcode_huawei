# 78. 子集

- 算法分类：回溯。
- 数据结构：路径数组、结果数组、递归栈。
- 对应代码：[078_subsets.cpp](./078_subsets.cpp)。
- 掌握状态：组合型回溯模板。

## 背诵答案

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(nums, 0, path, ans);
        return ans;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& path,
                   vector<vector<int>>& ans) {
        ans.push_back(path);

        int n = nums.size();
        for (int i = start; i < n; ++i) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, ans);
            path.pop_back();
        }
    }
};
```

## 背诵口诀

> 进入递归先收集；
> 从 `start` 开始选；
> 选择、递归、撤销。

子集问题和一般组合问题的区别是：每个递归节点的 `path` 都是一个合法答案，因此一进入递归就执行：

```cpp
ans.push_back(path);
```

`start` 保证下一层只选择当前位置后面的数字，避免产生重复子集或不同顺序的相同子集。

## 易错点

- 空集也是子集，所以第一次进入递归时就要收集空路径。
- 下一层从 `i + 1` 开始，不能重复选择同一个元素。
- 递归返回后必须 `path.pop_back()` 撤销选择。
- 题目保证数组元素互不相同，不需要排序去重。
- 不需要单独编写递归终止条件；当 `start == nums.size()` 时，循环自然结束。

共有 `2^n` 个子集，复制每个子集还需要最多 `O(n)` 时间，因此时间复杂度为 `O(n * 2^n)`；不计算答案，路径和递归栈空间复杂度为 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/backtracking/078_subsets.cpp -o build/078
./build/078
```
