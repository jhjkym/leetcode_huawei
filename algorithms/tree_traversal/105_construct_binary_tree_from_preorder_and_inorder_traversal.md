# 105. 从前序与中序遍历序列构造二叉树

- 算法分类：二叉树、递归、分治。
- 数据结构：数组、哈希表、递归栈。
- 对应代码：[105_construct_binary_tree_from_preorder_and_inorder_traversal.cpp](./105_construct_binary_tree_from_preorder_and_inorder_traversal.cpp)。
- 掌握状态：遍历序列建树模板。

## 背诵答案

```cpp
class Solution {
    unordered_map<int, int> position;
    int preorderIndex = 0;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        position.clear();
        preorderIndex = 0;
        int n = inorder.size();
        for (int i = 0; i < n; ++i) position[inorder[i]] = i;
        return build(preorder, 0, n - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        int mid = position[rootValue];

        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);
        return root;
    }
};
```

## 背诵口诀

> 前序依次取根，中序找到位置；
> 左区间建左树，右区间建右树。

前序遍历顺序是：

```text
根 -> 左 -> 右
```

因此使用 `preorderIndex` 从前向后依次取得每棵子树的根节点。中序遍历顺序是：

```text
左 -> 根 -> 右
```

根节点在中序数组中的位置 `mid`，会把当前区间分为左右子树：

```cpp
root->left = build(preorder, left, mid - 1);
root->right = build(preorder, mid + 1, right);
```

## 为什么先建左树

取出根节点后，前序数组中接下来出现的是左子树节点，然后才是右子树节点。因此递归顺序必须先左后右，才能让 `preorderIndex` 正确移动。

## 易错点

- 题目保证节点值互不相同，因此可以用值作为哈希表的键。
- 递归终止条件是 `left > right`。
- 必须先递归构造左子树，再构造右子树。
- 哈希表用于 `O(1)` 找到根节点的中序位置，避免每次线性搜索。
- 每次入口调用都要清空 `position` 并重置 `preorderIndex`。

每个节点创建一次，时间复杂度为 `O(n)`；哈希表和递归栈的空间复杂度为 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/105_construct_binary_tree_from_preorder_and_inorder_traversal.cpp -o build/105
./build/105
```
