# 21. 合并两个有序链表

- 算法分类：链表、双指针。
- 数据结构：单链表、哑节点。
- 对应代码：[021_merge_two_sorted_lists.cpp](./021_merge_two_sorted_lists.cpp)。
- 掌握状态：哑节点模板。

## 背诵答案

```cpp
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    tail->next = list1 ? list1 : list2;
    return dummy.next;
}
```

## 背诵口诀

> 小的接到尾，小链向后走；
> 尾巴跟着走，最后接剩余。

`dummy` 是固定的哑节点，使第一个节点和后续节点的处理方式相同；`tail` 始终指向合并后链表的最后一个节点。

每轮比较两个当前节点：

1. 将值较小的节点接到 `tail->next`；
2. 对应链表的指针向后移动；
3. `tail` 向后移动。

循环结束后，至少一条链表为空。另一条链表本身已经有序，可以整体接到末尾。

## 易错点

- 每轮最后不要忘记执行 `tail = tail->next`。
- 循环结束后要连接未遍历完的链表。
- 返回 `dummy.next`，不能返回局部变量 `dummy` 的地址。
- 算法复用原链表节点，不需要创建新的数据节点。

时间复杂度为 `O(m+n)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/linked_list/021_merge_two_sorted_lists.cpp -o build/021
./build/021
```
