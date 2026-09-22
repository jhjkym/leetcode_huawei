# 230. 二叉搜索树中第 K 小的元素

- 算法分类：二叉搜索树、迭代中序遍历。
- 数据结构：二叉树、栈。
- 对应代码：[230_kth_smallest_element_in_a_bst.cpp](./230_kth_smallest_element_in_a_bst.cpp)。
- 掌握状态：迭代中序遍历模板。

## 背诵答案

```cpp
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> nodes;

    while (root || !nodes.empty()) {
        while (root) {
            nodes.push(root);
            root = root->left;
        }

        root = nodes.top();
        nodes.pop();
        k--;
        if (k == 0) return root->val;

        root = root->right;
    }
    return -1;
}
```

## 背诵口诀

> 一路向左入栈；
> 弹出访问，`k--`；
> 然后转向右子树。

二叉搜索树的中序遍历顺序是：

```text
左子树 -> 根节点 -> 右子树
```

得到的节点值严格升序。因此每弹出一个节点，就表示访问了下一个较小元素。`k` 减到 `0` 时，当前节点就是第 `k` 小的元素。

## 易错点

- 外层条件是 `root || !nodes.empty()`，当前指针为空时，栈中可能仍有待访问节点。
- 内层循环负责把当前节点和所有左节点压栈。
- 节点弹栈时才算真正访问，此时执行 `k--`。
- 访问当前节点后必须转向 `root->right`。
- 题目保证 `k` 合法，所以正常情况下不会执行最后的 `return -1`。

最坏情况下访问所有节点，时间复杂度为 `O(n)`；栈空间复杂度为 `O(h)`。如果 `k` 较小，找到答案后会提前返回。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/230_kth_smallest_element_in_a_bst.cpp -o build/230
./build/230
```
