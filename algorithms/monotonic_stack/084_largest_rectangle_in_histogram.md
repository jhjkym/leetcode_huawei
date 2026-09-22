# 84. 柱状图中最大的矩形

- 算法分类：单调栈。
- 数据结构：保存下标的递增栈。
- 对应代码：[084_largest_rectangle_in_histogram.cpp](./084_largest_rectangle_in_histogram.cpp)。
- 掌握状态：单调栈求矩形模板。

## 背诵答案

```cpp
int largestRectangleArea(vector<int>& heights) {
    stack<int> indices;
    int n = heights.size();
    int ans = 0;

    for (int i = 0; i <= n; ++i) {
        int currentHeight = i == n ? 0 : heights[i];

        while (!indices.empty() &&
               currentHeight < heights[indices.top()]) {
            int height = heights[indices.top()];
            indices.pop();
            int width = indices.empty() ? i : i - indices.top() - 1;
            ans = max(ans, height * width);
        }
        indices.push(i);
    }
    return ans;
}
```

## 背诵口诀

> 栈中高度递增；
> 遇到更矮就弹出计算；
> 弹出后，左边界看新栈顶，右边界是当前位置；
> 末尾补零清空栈。

栈中保存柱子的下标。当遇到更矮的柱子时，说明栈顶柱子不能继续向右扩展：

```cpp
int height = heights[indices.top()];
indices.pop();
```

弹出后：

- 右侧第一个更矮柱子的下标是 `i`；
- 左侧第一个更矮柱子的下标是新的 `indices.top()`；
- 如果栈空，说明可以一直扩展到下标 `0`。

因此宽度为：

```cpp
indices.empty() ? i : i - indices.top() - 1
```

## 为什么末尾补零

递增到数组末尾的柱子没有遇到更矮元素，不会自动出栈。循环额外执行一次，并令：

```cpp
currentHeight = 0;
```

就能统一弹出并计算所有剩余柱子，不需要循环后再写一遍清栈逻辑。

## 易错点

- 栈中保存下标，不是高度，因为计算宽度需要位置。
- 必须先弹出，再使用新的栈顶计算左边界。
- 有左边界时宽度要减 `1`。
- 循环条件是 `i <= n`，最后一次代表虚拟的零高度柱子。
- 虚拟下标 `n` 只在最后被压栈，之后不会访问 `heights[n]`。

每个下标最多入栈、出栈各一次，时间复杂度为 `O(n)`，栈空间复杂度为 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/monotonic_stack/084_largest_rectangle_in_histogram.cpp -o build/084
./build/084
```
