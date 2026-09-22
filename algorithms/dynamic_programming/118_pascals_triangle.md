# 118. 杨辉三角

- 算法分类：动态规划、数组模拟。
- 数据结构：二维数组。
- 对应代码：[118_pascals_triangle.cpp](./118_pascals_triangle.cpp)。
- 掌握状态：逐行递推模板。

## 背诵答案

```cpp
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;

    for (int i = 0; i < numRows; ++i) {
        triangle.push_back(vector<int>(i + 1, 1));
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] +
                             triangle[i - 1][j];
        }
    }
    return triangle;
}
```

## 背诵口诀

> 第 `i` 行有 `i + 1` 个数；
> 两边先填 `1`；
> 中间等于上一行左上加右上。

先将新的一行全部初始化为 `1`：

```cpp
triangle.push_back(vector<int>(i + 1, 1));
```

每行只有下标 `1` 到 `i - 1` 是中间元素，需要根据上一行计算：

```cpp
triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
```

## 易错点

- 第 `i` 行的长度是 `i + 1`，因为下标从 `0` 开始。
- 每行两端已经初始化为 `1`，内层循环只处理 `1 <= j < i`。
- 中间元素来自上一行的 `j - 1` 和 `j`。
- 前两行没有中间元素，内层循环会自然跳过。

总共生成约 `numRows² / 2` 个元素，时间复杂度和返回结果空间都是 `O(numRows²)`；不计算返回结果时，额外空间为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/dynamic_programming/118_pascals_triangle.cpp -o build/118
./build/118
```
