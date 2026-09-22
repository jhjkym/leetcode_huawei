# 199. 二叉树的右视图

- 算法分类：二叉树、BFS、层序遍历。
- 数据结构：二叉树、队列。
- 对应代码：[199_binary_tree_right_side_view.cpp](./199_binary_tree_right_side_view.cpp)。
- 掌握状态：层序遍历变形模板。

## 背诵答案

```cpp
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<TreeNode*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        int size = nodes.size();
        while (size > 0) {
            TreeNode* node = nodes.front();
            nodes.pop();

            if (size == 1) ans.push_back(node->val);
            if (node->left) nodes.push(node->left);
            if (node->right) nodes.push(node->right);
            size--;
        }
    }
    return ans;
}
```

## 背诵口诀

> 层序遍历，每层最后一个加入答案。

每轮开始时先保存当前层节点数：

```cpp
int size = nodes.size();
```

内层循环每处理一个节点就执行 `size--`。因此在减一之前，`size == 1` 表示当前节点是本层最后一个节点，也就是从右侧能看到的节点。

## 易错点

- 必须保存当前层的原始队列长度，不能让新加入的下一层节点影响本层计数。
- 左孩子先入队、右孩子后入队，因此本层最后处理的是最右侧节点。
- 判断 `size == 1` 要放在 `size--` 之前。
- 空树返回空数组。

每个节点入队、出队各一次，时间复杂度为 `O(n)`；队列空间复杂度为 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/199_binary_tree_right_side_view.cpp -o build/199
./build/199
```
