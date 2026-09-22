# 287. 寻找重复数

## 最优背诵代码

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
```

## 为什么数组可以看成链表

把数组下标看成节点，把 `nums[i]` 看成节点 `i` 指向的下一个节点：

```text
i -> nums[i]
```

数组有 `n + 1` 个位置，而数字都在 `[1, n]` 范围内。重复数字会让两个位置指向同一个节点，因此从下标 `0` 出发一定会进入环，环的入口就是重复数字。

## 两个阶段

第一阶段寻找环内相遇点：

- 慢指针每次走一步：`slow = nums[slow]`。
- 快指针每次走两步：`fast = nums[nums[fast]]`。

第二阶段寻找环入口：

- 把慢指针放回下标 `0`。
- 两个指针都每次走一步。
- 再次相遇的位置就是环入口，也就是重复数字。

第一次相遇只保证在环内，不一定恰好位于环入口，所以不能直接返回。

## 背诵口诀

> 数值当下标，数组变链表；快二慢一先相遇，慢回零后一起走，再相遇就是重复数。

## 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(1)`
- 不修改原数组
