# 295. 数据流的中位数

- 算法分类：双堆、数据流。
- 数据结构：大顶堆、小顶堆。
- 对应代码：[295_find_median_from_data_stream.cpp](./295_find_median_from_data_stream.cpp)。
- 掌握状态：双堆中位数模板。

## 背诵答案

```cpp
class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() = default;

    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) return left.top();

        long long sum = left.top();
        sum += right.top();
        return sum / 2.0;
    }
};
```

## 背诵口诀

> 先进大顶堆；
> 大顶转小顶；
> 小顶更多时，再转回大顶。

两个堆始终满足：

1. `left` 保存较小的一半，是大顶堆；
2. `right` 保存较大的一半，是小顶堆；
3. `left.size()` 等于 `right.size()`，或者比它多 `1`。

因此：

- 元素总数为奇数时，中位数是 `left.top()`；
- 元素总数为偶数时，中位数是两个堆顶的平均值。

## 为什么固定转移两次

先把新数字放进 `left`，再把 `left` 最大值转移到 `right`，可以保证左半部分所有值不大于右半部分。若 `right` 数量更多，再把它的最小值转回 `left`，恢复数量平衡。

## 易错点

- `left` 是默认大顶堆，`right` 使用 `greater<int>` 构造小顶堆。
- 两堆相等时取两个堆顶的平均值；不相等时取 `left.top()`。
- 两个 `int` 堆顶先转成 `long long` 再相加，避免整数溢出。
- 题目保证调用 `findMedian` 时至少已经加入一个数字。

`addNum` 的时间复杂度为 `O(log n)`，`findMedian` 为 `O(1)`，空间复杂度为 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 data_structures/heap/295_find_median_from_data_stream.cpp -o build/295
./build/295
```
