# 148. 排序链表

- 算法分类：链表、归并排序、快慢指针。
- 数据结构：单链表、哑节点。
- 对应代码：[148_sort_list.cpp](./148_sort_list.cpp)。
- 掌握状态：链表归并排序模板。

## 背诵答案

```cpp
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* right = slow->next;
    slow->next = nullptr;

    ListNode* left = sortList(head);
    right = sortList(right);
    return merge(left, right);
}

ListNode* merge(ListNode* a, ListNode* b) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (a && b) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}
```

## 背诵口诀

> 快慢找中点，断开分两半；
> 左右分别排，最后合并链。

归并排序分为三步：

1. 用快慢指针找到左半段的最后一个节点 `slow`；
2. 从 `slow->next` 处断开，递归排序左右两段；
3. 使用第 21 题的模板合并两个有序链表。

## 为什么 `fast = head->next`

让快指针从第二个节点出发，偶数长度时 `slow` 会停在左半段末尾。例如两个节点时，`slow` 仍停在第一个节点，可以顺利断成两个单节点链表。

如果 `fast` 和 `slow` 都从 `head` 出发，两个节点时 `slow` 可能走到第二个节点，链表无法正确缩小，导致无限递归。

## 易错点

- 递归终止条件是空链表或单节点链表。
- 找到中点后必须执行 `slow->next = nullptr`，真正断开两段。
- 快指针从 `head->next` 出发。
- 合并时复用原节点，不需要创建新的数据节点。

时间复杂度为 `O(n log n)`。递归栈深度为 `O(log n)`，额外空间复杂度为 `O(log n)`；自底向上的迭代归并可做到 `O(1)` 额外空间，但代码更长，不适合作为首选背诵版本。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/linked_list/148_sort_list.cpp -o build/148
./build/148
```
