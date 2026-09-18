# 240. 搜索二维矩阵 II

- 算法分类：矩阵搜索、楼梯式搜索。
- 数据结构：二维数组。
- 对应代码：[240_search_a_2d_matrix_ii.cpp](./240_search_a_2d_matrix_ii.cpp)。
- 掌握状态：**不会，已提供答案模板，待复习背诵。**

## 背诵答案

从右上角开始：当前位置比目标小，向下；当前位置比目标大，向左；相等则找到。

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int row = 0;
    int col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) return true;
        if (matrix[row][col] < target) ++row;
        else --col;
    }
    return false;
}
```

**口诀：右上开始走，小了向下，大了向左。**

右上角同时具有两个方向的单调性：向左数字变小，向下数字变大。每次比较都能排除一整行或一整列，所以无需遍历所有元素。

## 易错点与复杂度

- 当前位置小于 `target` 时向下，不是向右；当前位置大于 `target` 时向左。
- 空矩阵或空行直接返回 `false`。
- 使用下标 `row、col`，不要复制矩阵。
- 每次只移动一个方向，不能同时移动行列。
- 行数为 `m`、列数为 `n` 时，时间复杂度 `O(m+n)`，辅助空间 `O(1)`。

## 测试结果

16 组固定测例覆盖典型矩阵、空边界、单行、单列、重复数字、正负数和数值边界。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/matrix_search/240_search_a_2d_matrix_ii.cpp -o build/240
./build/240
```
