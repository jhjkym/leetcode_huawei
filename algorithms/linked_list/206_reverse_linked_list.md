# 206. 反转链表

- 算法分类：链表、迭代、双指针。
- 数据结构：单链表节点。
- 对应代码：[206_reverse_linked_list.cpp](./206_reverse_linked_list.cpp)。
- 掌握状态：链表三指针模板。

## 背诵答案

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;

    while (cur != nullptr) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
```

## 背诵口诀

> 保存下一个，反转当前，两个指针向后走。

每轮循环固定四步：

```cpp
ListNode* next = cur->next; // 1. 保存下一个
cur->next = prev;           // 2. 反转当前指针
prev = cur;                 // 3. prev 向后走
cur = next;                 // 4. cur 向后走
```

循环结束时，`cur` 指向空，`prev` 指向反转后链表的新头节点，因此返回 `prev`。

## 易错点

- 必须先保存 `cur->next`，否则反转后会丢失后续链表。
- `prev` 初始为 `nullptr`，这样原头节点会自然成为新尾节点。
- 最后返回 `prev`，不是已经指向空的 `cur`。
- 空链表和单节点链表不需要单独判断，这个模板会自然处理。

时间复杂度为 `O(n)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/linked_list/206_reverse_linked_list.cpp -o build/206
./build/206
```
