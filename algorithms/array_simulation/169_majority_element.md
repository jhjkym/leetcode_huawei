# 169. 多数元素

## 最优背诵代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }

            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};
```

## 思路

使用摩尔投票法，把一个多数元素和一个非多数元素互相抵消。

- `candidate` 表示当前候选人。
- `count` 表示当前候选人拥有的票数。
- 遇到候选人，票数加一。
- 遇到其他数字，票数减一。
- 票数归零，说明此前的数字已经两两抵消，下一个数字成为新候选人。

多数元素出现次数超过数组长度的一半。即使它不断与其他元素抵消，最后留下的候选人仍然一定是多数元素。

题目保证多数元素存在，所以最后可以直接返回 `candidate`，不需要再次统计验证。

## 背诵口诀

> 票数为零换候选；相同加一，不同减一；最后候选就是答案。

## 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(1)`
