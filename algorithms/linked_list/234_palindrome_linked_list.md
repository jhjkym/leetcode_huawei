# 234. 回文链表

- 算法分类：快慢指针、反转链表。
- 数据结构：单链表节点。
- 对应代码：[234_palindrome_linked_list.cpp](./234_palindrome_linked_list.cpp)。
- 掌握状态：链表综合模板。

## 背诵答案

```cpp
bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* right = reverseList(slow);
    ListNode* left = head;
    while (right) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }
    return true;
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
```

## 背诵口诀

> 快慢找中点，反转后半段，两头依次比。

分为三步：

1. `slow` 每次走一步，`fast` 每次走两步；循环结束时 `slow` 到达后半段开头。
2. 反转以 `slow` 开头的后半段。
3. `left` 从原头节点出发，`right` 从反转后的头节点出发，逐个比较。

只需要在 `right` 不为空时比较，因为它代表需要检查的半条链表。奇数长度时，中间节点会参与一次比较，不影响结果。

## 易错点

- 快指针条件必须是 `fast && fast->next`，否则访问 `fast->next->next` 可能越界。
- 比较节点的 `val`，不是比较节点指针。
- 第二段需要先反转，否则单链表无法从尾部向前遍历。
- 当前最简模板会改变后半段的指针方向；题目只要求判断结果，因此允许这样处理。

找中点、反转和比较都是线性操作，时间复杂度为 `O(n)`；只使用若干指针，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/linked_list/234_palindrome_linked_list.cpp -o build/234
./build/234
```
