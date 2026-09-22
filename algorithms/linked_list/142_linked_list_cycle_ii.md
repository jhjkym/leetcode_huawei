# 142. 环形链表 II

- 算法分类：Floyd 判圈、快慢指针。
- 数据结构：单链表节点。
- 对应代码：[142_linked_list_cycle_ii.cpp](./142_linked_list_cycle_ii.cpp)。
- 掌握状态：寻找环入口模板。

## 背诵答案

```cpp
ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            ListNode* cur = head;
            while (cur != slow) {
                cur = cur->next;
                slow = slow->next;
            }
            return cur;
        }
    }
    return nullptr;
}
```

## 背诵口诀

> 快慢先相遇，一个回到头；
> 两个同步走，再遇是入口。

第 141 题只能判断是否有环；本题在快慢指针相遇后增加第二阶段：

1. 保留 `slow` 在相遇点；
2. 让 `cur` 从头节点出发；
3. `cur` 和 `slow` 每次各走一步；
4. 两者相遇的位置就是环的入口。

## 为什么第二次相遇是入口

设头节点到环入口的距离为 `a`，环入口到第一次相遇点的距离为 `b`，环剩余部分长度为 `c`。

第一次相遇时，慢指针走了 `a + b`，快指针比慢指针多走若干整圈，因此可以推出：

```text
a = 若干整圈长度 - b
```

也就是说，从头节点走到入口的距离，等于从相遇点继续走到入口的距离（允许多绕几圈）。所以两个指针同步前进，必定在入口相遇。

## 易错点

- 第一阶段仍要检查 `fast && fast->next`。
- 只有快慢指针相遇后，才能开始寻找入口。
- 第二阶段两个指针都必须每次走一步。
- 返回的是节点地址，不是入口节点的值或下标。
- 如果快指针到达空指针，说明无环，返回 `nullptr`。

时间复杂度为 `O(n)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/linked_list/142_linked_list_cycle_ii.cpp -o build/142
./build/142
```
