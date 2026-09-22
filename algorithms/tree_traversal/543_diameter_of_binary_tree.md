# 543. 二叉树的直径

- 算法分类：二叉树、递归 DFS。
- 数据结构：二叉树、递归栈。
- 对应代码：[543_diameter_of_binary_tree.cpp](./543_diameter_of_binary_tree.cpp)。
- 掌握状态：树高与路径模板。

## 背诵答案

```cpp
class Solution {
    int ans = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        depth(root);
        return ans;
    }

private:
    int depth(TreeNode* root) {
        if (!root) return 0;

        int left = depth(root->left);
        int right = depth(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
};
```

## 背诵口诀

> 返回最大深度，顺便更新直径；
> 深度是 `max + 1`，直径是 `left + right`。

`depth(root)` 返回以当前节点为根的最大深度：

```cpp
return max(left, right) + 1;
```

经过当前节点的最长路径，会从左子树最深处经过当前节点，再走到右子树最深处。题目按边数计算直径，因此正好是：

```cpp
left + right
```

对每个节点都更新一次全局最大值，就能得到整棵树的直径。最长路径不一定经过整棵树的根节点。

## 易错点

- 深度按节点数计算，需要 `+1`；直径按边数计算，直接使用 `left + right`，不加 `1`。
- `depth` 返回深度，不是返回直径。
- 每次调用入口函数时将 `ans` 重置为 `0`，避免同一个对象多次调用时保留旧答案。
- 空树和单节点树的直径都是 `0`。

每个节点访问一次，时间复杂度为 `O(n)`；递归栈空间复杂度为 `O(h)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/543_diameter_of_binary_tree.cpp -o build/543
./build/543
```
