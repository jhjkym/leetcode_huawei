# 55. 跳跃游戏

- 算法分类：贪心。
- 数据结构：数组、最远位置变量。
- 对应代码：[055_jump_game.cpp](./055_jump_game.cpp)。
- 掌握状态：最远覆盖范围模板。

## 背诵答案

```cpp
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int farthest = 0;

    for (int i = 0; i < n; ++i) {
        if (i > farthest) return false;
        farthest = max(farthest, i + nums[i]);
        if (farthest >= n - 1) return true;
    }
    return true;
}
```

## 背诵口诀

> 当前位置到不了，直接失败；
> 否则更新最远位置；
> 最远位置覆盖终点，直接成功。

`farthest` 表示此前所有可达位置能够覆盖的最远下标。

- 如果 `i > farthest`，当前位置无法到达，后面的位置自然也无法到达；
- 如果当前位置可达，就用 `i + nums[i]` 更新最远覆盖范围；
- 一旦覆盖最后一个下标，就可以提前返回 `true`。

## 易错点

- 必须先判断当前位置是否可达，再用它更新 `farthest`。
- 判断无法到达的条件是 `i > farthest`，不是 `i >= farthest`；等于时仍然可以到达当前位置。
- 只有一个元素时，起点就是终点，应返回 `true`。
- 本题只判断能否到达，不需要计算最少跳跃次数；最少次数是第 45 题。

每个位置最多访问一次，时间复杂度为 `O(n)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/sorting_greedy/055_jump_game.cpp -o build/055
./build/055
```
