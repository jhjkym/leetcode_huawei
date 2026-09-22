# 25. K 个一组翻转链表

- 算法分类：链表、分组反转。
- 数据结构：单链表、哑节点。
- 对应代码：[025_reverse_nodes_in_k_group.cpp](./025_reverse_nodes_in_k_group.cpp)。
- 掌握状态：链表分组反转模板。

## 背诵答案

```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* groupPrev = &dummy;

    while (true) {
        ListNode* kth = getKth(groupPrev, k);
        if (!kth) break;
        ListNode* groupNext = kth->next;

        ListNode* prev = groupNext;
        ListNode* cur = groupPrev->next;
        while (cur != groupNext) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        ListNode* groupFirst = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = groupFirst;
    }
    return dummy.next;
}

ListNode* getKth(ListNode* cur, int k) {
    while (cur && k > 0) {
        cur = cur->next;
        k--;
    }
    return cur;
}
```

## 背诵口诀

> 找到第 `k` 个，记住下一组；
> 当前组反转，前驱移到组尾。

每轮处理一组，关键节点为：

```text
groupPrev -> groupFirst -> ... -> kth -> groupNext
```

处理步骤：

1. 从 `groupPrev` 出发找第 `k` 个节点 `kth`；找不到说明剩余不足 `k` 个，直接结束。
2. 保存 `groupNext = kth->next`，它既是反转终点，也是本组新尾节点应连接的位置。
3. 使用第 206 题的三指针模板反转 `[groupFirst, groupNext)`。
4. 让 `groupPrev` 接到新组头 `kth`，再移动到新组尾 `groupFirst`。

## 为什么 `prev = groupNext`

普通反转链表时，`prev` 从 `nullptr` 开始；这里只反转一段，所以让 `prev` 从 `groupNext` 开始。这样原来的组头反转后会直接连接下一组，不需要额外接尾操作。

## 易错点

- `getKth` 从组前驱 `groupPrev` 出发，向后走 `k` 步。
- 剩余节点不足 `k` 个时保持原顺序。
- 反转前必须保存 `groupNext`。
- 连接新组头之前先保存 `groupFirst`，因为它反转后会成为组尾。
- 每组结束后执行 `groupPrev = groupFirst`。

每个节点只被处理常数次，时间复杂度为 `O(n)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/linked_list/025_reverse_nodes_in_k_group.cpp -o build/025
./build/025
```
