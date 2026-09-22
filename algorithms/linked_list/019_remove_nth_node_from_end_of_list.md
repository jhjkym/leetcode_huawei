# 19. 删除链表的倒数第 N 个结点

- 算法分类：链表、快慢指针。
- 数据结构：单链表、哑节点。
- 对应代码：[019_remove_nth_node_from_end_of_list.cpp](./019_remove_nth_node_from_end_of_list.cpp)。
- 掌握状态：固定间距双指针模板。

## 背诵答案

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* slow = &dummy;
    ListNode* fast = &dummy;

    for (int i = 0; i < n; ++i) fast = fast->next;

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* target = slow->next;
    slow->next = target->next;
    delete target;
    return dummy.next;
}
```

## 背诵口诀

> 快指针先走 `n` 步；
> 快慢一起走，慢指针停在删除点之前。

两个指针都从哑节点出发。快指针先走 `n` 步后，它和慢指针之间相隔 `n` 个节点。当 `fast->next` 为空时，`fast` 位于尾节点，`slow->next` 恰好是倒数第 `n` 个节点。

使用哑节点可以统一处理删除头节点的情况：即使要删除原头节点，`slow` 也能停在它前面的 `dummy` 上。

## 易错点

- 快慢指针都从 `dummy` 出发。
- 快指针先走恰好 `n` 步。
- 同步移动的条件是 `fast->next`，这样 `slow` 才会停在待删除节点的前一个位置。
- 返回 `dummy.next`，因为原头节点可能被删除。
- 题目保证 `n` 合法，因此快指针提前移动时不会越过空指针。

时间复杂度为 `O(L)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/linked_list/019_remove_nth_node_from_end_of_list.cpp -o build/019
./build/019
```
