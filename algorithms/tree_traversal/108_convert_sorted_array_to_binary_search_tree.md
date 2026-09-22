# 108. 将有序数组转换为二叉搜索树

- 算法分类：二叉树、分治、递归 DFS。
- 数据结构：有序数组、二叉搜索树。
- 对应代码：[108_convert_sorted_array_to_binary_search_tree.cpp](./108_convert_sorted_array_to_binary_search_tree.cpp)。
- 掌握状态：数组建平衡树模板。

## 背诵答案

```cpp
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return build(nums, 0, n - 1);
    }

private:
    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, left, mid - 1);
        root->right = build(nums, mid + 1, right);
        return root;
    }
};
```

## 背诵口诀

> 中点做根；左区间建左树，右区间建右树。

有序数组的中点把区间分成大小接近的两部分：

- 左边的值都小于根节点，递归构造左子树；
- 右边的值都大于根节点，递归构造右子树；
- 两边节点数量最多相差一个，因此得到高度平衡的 BST。

## 易错点

- 递归终止条件是 `left > right`。
- 左区间是 `[left, mid - 1]`，右区间是 `[mid + 1, right]`。
- 使用 `left + (right - left) / 2` 计算中点。
- 先保存 `int n = nums.size()`，再传入 `n - 1`；这样空数组时右边界为 `-1`，不会发生无符号整数下溢。
- 题目允许多个正确答案，选择左中点或右中点都可以。

每个数组元素创建一个节点，时间复杂度为 `O(n)`；递归栈空间复杂度为 `O(log n)`，返回树所占空间为 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/tree_traversal/108_convert_sorted_array_to_binary_search_tree.cpp -o build/108
./build/108
```
