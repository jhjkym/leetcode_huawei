# 73. 矩阵置零

- 算法分类：矩阵模拟、原地标记。
- 数据结构：二维数组。
- 对应代码：[073_set_matrix_zeroes.cpp](./073_set_matrix_zeroes.cpp)。
- 掌握状态：首行首列标记模板。

## 背诵答案

```cpp
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRow = false, firstCol = false;

    for (int j = 0; j < n; ++j)
        if (matrix[0][j] == 0) firstRow = true;
    for (int i = 0; i < m; ++i)
        if (matrix[i][0] == 0) firstCol = true;

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if (firstRow) fill(matrix[0].begin(), matrix[0].end(), 0);
    if (firstCol)
        for (int i = 0; i < m; ++i) matrix[i][0] = 0;
}
```

## 背诵口诀

> 先记首行首列，内层零做标记；
> 根据标记置零，最后处理首行首列。

首行和首列既是矩阵的一部分，也被当作标记数组使用：

- `matrix[i][0] == 0` 表示第 `i` 行需要置零；
- `matrix[0][j] == 0` 表示第 `j` 列需要置零。

因为首行和首列会被覆盖，所以先用 `firstRow` 和 `firstCol` 保存它们原本是否含零。处理中间区域后，最后再处理首行和首列。

## 易错点

- 必须先记录首行、首列原本是否有零。
- 标记和根据标记置零时，都从下标 `1` 开始。
- 首行、首列必须最后处理，否则会制造新标记，导致不该置零的位置也变成零。
- 题目保证矩阵非空。

时间复杂度为 `O(mn)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/matrix_simulation/073_set_matrix_zeroes.cpp -o build/073
./build/073
```
