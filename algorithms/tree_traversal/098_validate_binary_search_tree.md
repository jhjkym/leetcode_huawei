# 98. 验证二叉搜索树

- 算法分类：二叉树、递归 DFS、上下界。
- 数据结构：二叉搜索树、递归栈。
- 对应代码：[098_validate_binary_search_tree.cpp](./098_validate_binary_search_tree.cpp)。
- 掌握状态：BST 上下界模板。

## 背诵答案

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool isValid(TreeNode* root, long long lower, long long upper) {
        if (!root) return true;
        if (root->val <= lower || root->val >= upper) return false;

        return isValid(root->left, lower, root->val) &&
               isValid(root->right, root->val, upper);
    }
};
```

## 背诵口诀

> 当前节点在上下界之间；
> 向左收紧上界，向右收紧下界。

对当前节点 `root`：

```text
lower < root->val < upper
```

进入左子树时，所有节点都必须小于当前值，所以当前值成为新的上界：

```cpp
isValid(root->left, lower, root->val)
```

进入右子树时，所有节点都必须大于当前值，所以当前值成为新的下界：

```cpp
isValid(root->right, root->val, upper)
```

## 易错点

- BST 要求严格小于和严格大于，重复值不合法。
- 不能只比较节点和它的直接孩子；祖先节点传下来的限制同样必须满足。
- 初始边界使用 `LLONG_MIN` 和 `LLONG_MAX`，因为节点值可能等于 `INT_MIN` 或 `INT_MAX`。
- 空树符合 BST 定义，返回 `true`。

每个节点访问一次，时间复杂度为 `O(n)`；递归栈空间复杂度为 `O(h)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/098_validate_binary_search_tree.cpp -o build/098
./build/098
```
