# 138. 随机链表的复制

- 算法分类：链表、哈希表。
- 数据结构：单链表、`unordered_map`。
- 对应代码：[138_copy_list_with_random_pointer.cpp](./138_copy_list_with_random_pointer.cpp)。
- 掌握状态：两遍哈希表模板。

## 背诵答案

```cpp
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    unordered_map<Node*, Node*> copy;
    for (Node* cur = head; cur; cur = cur->next) {
        copy[cur] = new Node(cur->val);
    }

    for (Node* cur = head; cur; cur = cur->next) {
        copy[cur]->next = copy[cur->next];
        copy[cur]->random = copy[cur->random];
    }
    return copy[head];
}
```

## 背诵口诀

> 第一遍复制节点，第二遍复制指针。

哈希表保存：

```text
原节点地址 -> 新节点地址
```

第一遍只创建所有新节点。这样进入第二遍时，无论 `next` 或 `random` 指向哪个节点，都能直接从哈希表找到对应的新节点。

```cpp
copy[cur]->next = copy[cur->next];
copy[cur]->random = copy[cur->random];
```

当键为 `nullptr` 时，`unordered_map` 的 `operator[]` 会得到默认值 `nullptr`，因此不需要分别判断两个指针是否为空。

## 易错点

- 哈希表必须使用节点地址作为键，不能使用节点值，因为节点值可能重复。
- 第二遍连接的目标必须是 `copy[cur->next]` 和 `copy[cur->random]`，不能指回原链表。
- 必须先创建完所有新节点，再连接随机指针。
- 空链表直接返回 `nullptr`。

时间复杂度为 `O(n)`，哈希表和新链表占用 `O(n)` 空间；不计算返回的新链表时，额外空间复杂度为 `O(n)`。

## 为什么选择这个版本

穿插节点法可以把额外空间降到 `O(1)`，但需要经历“插入复制节点、连接随机指针、拆分两条链表”三个阶段，指针细节更多。两遍哈希表法结构固定、容易背诵，也更不容易破坏原链表。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/linked_list/138_copy_list_with_random_pointer.cpp -o build/138
./build/138
```
