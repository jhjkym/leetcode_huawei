# 23. 合并 K 个升序链表

- 算法分类：链表、两两归并。
- 数据结构：单链表、哑节点。
- 对应代码：[023_merge_k_sorted_lists.cpp](./023_merge_k_sorted_lists.cpp)。
- 掌握状态：多路归并模板。

## 背诵答案

```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    for (int step = 1; step < n; step *= 2) {
        for (int i = 0; i + step < n; i += step * 2) {
            lists[i] = merge(lists[i], lists[i + step]);
        }
    }
    return n == 0 ? nullptr : lists[0];
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

> 步长从 `1` 开始，每轮翻倍；
> 相隔一个步长的两条链表进行合并。

直接复用第 21 题“合并两个有序链表”的模板：

```text
step = 1：合并 0和1、2和3、4和5……
step = 2：合并 0和2、4和6……
step = 4：合并 0和4、8和12……
```

每轮结束后，已经合并的链表规模约翻倍，因此 `step *= 2`。最终所有节点都合并到 `lists[0]`。

## 两层循环怎么记

```cpp
for (int step = 1; step < n; step *= 2) {
    for (int i = 0; i + step < n; i += step * 2) {
        lists[i] = merge(lists[i], lists[i + step]);
    }
}
```

- `step *= 2`：每轮链表规模翻倍；
- `i += step * 2`：跳到下一对；
- `i + step`：找到当前链表的配对链表。

## 易错点

- `lists` 为空时返回 `nullptr`，不能直接访问 `lists[0]`。
- 内层条件是 `i + step < n`，没有配对的链表留到下一轮。
- 合并函数直接复用第 21 题的 `dummy + tail` 模板。
- 算法复用原链表节点，不需要创建新的数据节点。

设所有链表共有 `N` 个节点、链表数量为 `k`。归并共有 `log k` 轮，每轮处理所有节点，时间复杂度为 `O(N log k)`；迭代归并只使用若干指针，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/linked_list/023_merge_k_sorted_lists.cpp -o build/023
./build/023
```
