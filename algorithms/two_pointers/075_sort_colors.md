# 75. 颜色分类

## 最优背诵代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int i = 0;
        int right = nums.size() - 1;

        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            } else {
                i++;
            }
        }
    }
};
```

## 思路

维护三个区域：

```text
[0, left - 1]       全是 0
[left, i - 1]       全是 1
[i, right]          尚未检查
[right + 1, n - 1]  全是 2
```

检查 `nums[i]`：

- 等于 `0`：与 `left` 交换，`left` 和 `i` 都向右移动。
- 等于 `1`：位置正确，`i` 向右移动。
- 等于 `2`：与 `right` 交换，只让 `right` 向左移动。

## 遇到 2 为什么不能移动 `i`

从右边交换回来的数字还没有检查，可能是 `0`、`1` 或 `2`，因此下一轮仍要检查当前位置。

遇到 `0` 时可以移动 `i`，因为 `left` 左边都是 `0`，而当 `left < i` 时，`left` 位置原来一定是已经检查过的 `1`。

## 背诵口诀

> 零换左边，左右一起走；一直接走；二换右边，只收右边不走当前。

## 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(1)`
