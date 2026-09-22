# 2. 两数相加

- 算法分类：链表、竖式加法模拟。
- 数据结构：单链表、哑节点。
- 对应代码：[002_add_two_numbers.cpp](./002_add_two_numbers.cpp)。
- 掌握状态：链表加法模板。

## 背诵答案

```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        tail->next = new ListNode(sum % 10);
        tail = tail->next;
        carry = sum / 10;
    }
    return dummy.next;
}
```

## 背诵口诀

> 两数加进位，个位建节点，十位留进位。

链表已经按个位到高位的顺序存储，正好可以从头开始模拟竖式加法：

```cpp
当前位 = sum % 10;
新进位 = sum / 10;
```

循环条件写成 `l1 || l2 || carry`，可以统一处理：

- 两条链表长度不同；
- 某条链表已经遍历结束；
- 最后仍有一个进位需要创建节点。

## 易错点

- 每轮的 `sum` 必须从上一轮的 `carry` 开始。
- 只有指针非空时才能读取节点值并向后移动。
- 循环条件不能漏掉 `carry`，例如 `5 + 5` 还需要额外节点 `1`。
- 返回 `dummy.next`，并在创建节点后移动 `tail`。

设两条链表的最大长度为 `n`，时间复杂度为 `O(n)`；返回结果所需空间为 `O(n)`，除此之外的额外空间为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/linked_list/002_add_two_numbers.cpp -o build/002
./build/002
```
