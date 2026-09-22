# 141. 环形链表

- 算法分类：Floyd 判圈、快慢指针。
- 数据结构：单链表节点。
- 对应代码：[141_linked_list_cycle.cpp](./141_linked_list_cycle.cpp)。
- 掌握状态：快慢指针判环模板。

## 背诵答案

```cpp
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

## 背诵口诀

> 慢走一步，快走两步；
> 相遇就是有环，快到空就是无环。

如果链表无环，快指针最终会到达 `nullptr`。如果链表有环，两个指针进入环后，快指针每轮会追近慢指针一步，最终一定相遇。

## 易错点

- 循环条件必须同时检查 `fast` 和 `fast->next`，才能安全执行 `fast->next->next`。
- 必须先移动指针，再判断是否相遇。若两个指针都从 `head` 出发却在移动前判断，它们一开始就相等，会误判所有链表都有环。
- 判断的是节点地址 `slow == fast`，不是节点值。
- 空链表、单个无环节点会自然返回 `false`；单节点自环会返回 `true`。

时间复杂度为 `O(n)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/linked_list/141_linked_list_cycle.cpp -o build/141
./build/141
```
