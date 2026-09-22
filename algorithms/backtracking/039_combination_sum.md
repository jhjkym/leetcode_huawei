# 39. 组合总和

- 算法分类：回溯、排序剪枝。
- 数据结构：路径数组、递归栈。
- 对应代码：[039_combination_sum.cpp](./039_combination_sum.cpp)。
- 掌握状态：可重复选择的组合模板。

## 背诵答案

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(candidates, target, 0, path, ans);
        return ans;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& path, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        int n = candidates.size();
        for (int i = start; i < n && candidates[i] <= target; ++i) {
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, path, ans);
            path.pop_back();
        }
    }
};
```

## 背诵口诀

> 排序以后方便剪枝；
> 从 `start` 开始选择；
> 可以重复，下一层仍传 `i`；
> 选择、递归、撤销。

`target` 表示当前还需要凑出的数值。选择 `candidates[i]` 后，下一层目标变为：

```cpp
target - candidates[i]
```

因为同一个数字可以无限次使用，下一层仍从下标 `i` 开始。如果传 `i + 1`，每个数字就只能使用一次。

## 为什么不会产生重复组合

每层只从 `start` 向后选择，因此路径中的数字下标不会倒退。例如会生成 `[2, 2, 3]`，但不会再生成排列不同、实际相同的 `[3, 2, 2]`。

## 易错点

- 找到 `target == 0` 时收集答案并立即返回。
- 递归传入的是 `i`，不是 `i + 1`。
- 先排序后，若 `candidates[i] > target`，后面的数字也不可能选择，可以停止循环。
- 递归返回后必须撤销最后一次选择。
- 题目保证候选数字互不相同，因此不需要同层去重。

回溯算法的时间复杂度取决于答案数量和搜索树规模，常写作指数级；递归深度最多为 `target / min(candidates)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/backtracking/039_combination_sum.cpp -o build/039
./build/039
```
