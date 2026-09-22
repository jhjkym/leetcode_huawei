# 74. 搜索二维矩阵

- 算法分类：二分查找、矩阵一维化。
- 数据结构：二维矩阵。
- 对应代码：[074_search_a_2d_matrix.cpp](./074_search_a_2d_matrix.cpp)。
- 掌握状态：矩阵二分模板。

## 背诵答案

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0;
    int right = m * n;

    while (left < right) {
        int mid = left + (right - left) / 2;
        int value = matrix[mid / n][mid % n];

        if (value < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left < m * n && matrix[left / n][left % n] == target;
}
```

## 背诵口诀

> 矩阵看成一维数组；
> 下标除列数得到行，取模得到列；
> 二分找第一个大于等于目标的位置。

矩阵满足每行升序，并且下一行首元素大于上一行末元素，因此按行展开后是完整的升序数组。

一维下标 `index` 对应的二维位置为：

```cpp
row = index / n;
col = index % n;
```

直接复用第 35 题的左闭右开二分模板。循环结束后，`left` 是第一个大于等于 `target` 的位置，再判断它是否真的等于目标值。

## 易错点

- 总元素数量是 `m * n`，右边界使用开区间。
- 映射时除数和模数都是列数 `n`，不是行数 `m`。
- 二分结束后先检查 `left < m * n`，再访问矩阵。
- 本地代码额外处理了空矩阵。

时间复杂度为 `O(log(mn))`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/matrix_search/074_search_a_2d_matrix.cpp -o build/074
./build/074
```
