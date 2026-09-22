# 94. 二叉树的中序遍历

- 算法分类：二叉树、递归 DFS。
- 数据结构：二叉树、递归栈。
- 对应代码：[094_binary_tree_inorder_traversal.cpp](./094_binary_tree_inorder_traversal.cpp)。
- 掌握状态：树的遍历基础模板。

## 背诵答案

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

private:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
};
```

## 背诵口诀

> 左、根、右。

递归函数只做三件事：

```cpp
inorder(root->left, ans);   // 左
ans.push_back(root->val);   // 根
inorder(root->right, ans);  // 右
```

访问根节点代码放在哪里，就决定是哪一种遍历：

- 根、左、右：前序遍历；
- 左、根、右：中序遍历；
- 左、右、根：后序遍历。

## 易错点

- 空节点必须直接返回，这是递归终止条件。
- 中序遍历是在左右两次递归之间记录根节点。
- `ans` 使用引用传递，所有递归调用共同写入同一个结果数组。
- 二叉搜索树的中序遍历结果是升序序列。

每个节点访问一次，时间复杂度为 `O(n)`；递归栈空间复杂度为 `O(h)`，其中 `h` 是树高。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/094_binary_tree_inorder_traversal.cpp -o build/094
./build/094
```
