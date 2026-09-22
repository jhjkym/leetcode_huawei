# 24. 两两交换链表中的节点

- 算法分类：链表、迭代。
- 数据结构：单链表、哑节点。
- 对应代码：[024_swap_nodes_in_pairs.cpp](./024_swap_nodes_in_pairs.cpp)。
- 掌握状态：链表局部交换模板。

## 背诵答案

```cpp
ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* cur = &dummy;

    while (cur->next && cur->next->next) {
        ListNode* first = cur->next;
        ListNode* second = first->next;

        first->next = second->next;
        second->next = first;
        cur->next = second;

        cur = first;
    }
    return dummy.next;
}
```

## 背诵口诀

> 一接三，二接一，前驱接二；
> 前驱走到一，继续下一对。

交换前的局部结构为：

```text
cur -> first -> second -> next
```

交换后变为：

```text
cur -> second -> first -> next
```

对应三个指针修改：

```cpp
first->next = second->next; // 一接三
second->next = first;       // 二接一
cur->next = second;         // 前驱接二
```

交换完成后，`first` 位于这一对的末尾，所以执行 `cur = first`，继续处理下一对。

## 易错点

- 循环前必须确认后面至少还有两个节点：`cur->next && cur->next->next`。
- 题目要求交换节点，不能只交换节点中的数值。
- 三次连接后不要忘记将 `cur` 移动到 `first`。
- 使用哑节点可以统一处理原头节点参与交换的情况。

时间复杂度为 `O(n)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/linked_list/024_swap_nodes_in_pairs.cpp -o build/024
./build/024
```
