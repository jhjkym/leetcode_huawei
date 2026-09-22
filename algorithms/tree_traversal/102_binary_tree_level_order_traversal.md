# 102. 二叉树的层序遍历

- 算法分类：二叉树、BFS。
- 数据结构：二叉树、队列。
- 对应代码：[102_binary_tree_level_order_traversal.cpp](./102_binary_tree_level_order_traversal.cpp)。
- 掌握状态：层序遍历模板。

## 背诵答案

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    queue<TreeNode*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        int size = nodes.size();
        vector<int> level;

        while (size > 0) {
            TreeNode* node = nodes.front();
            nodes.pop();
            level.push_back(node->val);

            if (node->left) nodes.push(node->left);
            if (node->right) nodes.push(node->right);
            size--;
        }
        ans.push_back(level);
    }
    return ans;
}
```

## 背诵口诀

> 根节点先入队；
> 每轮记队长，队长就是当前层节点数；
> 出队一个，孩子入队。

外层循环控制层数，内层循环处理当前层。必须在内层循环开始前保存：

```cpp
int size = nodes.size();
```

因为处理当前层时会把下一层节点加入队列，队列长度会不断变化。保存原长度后，内层循环只会处理本层节点。

## 易错点

- 空树直接返回空数组。
- 必须先记录当前层的队列长度，再向队列加入孩子。
- 节点出队后，依次将非空的左右孩子入队。
- 每层遍历结束后，才把 `level` 加入答案。

每个节点入队、出队各一次，时间复杂度为 `O(n)`；队列最多保存一层节点，空间复杂度为 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/102_binary_tree_level_order_traversal.cpp -o build/102
./build/102
```
