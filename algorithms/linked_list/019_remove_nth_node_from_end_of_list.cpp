#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 19. 删除链表的倒数第 N 个结点
// 快指针先走 n 步，再与慢指针同步移动。
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        for (int i = 0; i < n; ++i) fast = fast->next;

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* target = slow->next;
        slow->next = target->next;
        delete target;
        return dummy.next;
    }
};

ListNode* buildList(const vector<int>& values) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }
    return dummy.next;
}

vector<int> toVector(ListNode* head) {
    vector<int> values;
    while (head != nullptr) {
        values.push_back(head->val);
        head = head->next;
    }
    return values;
}

void destroyList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    struct TestCase {
        vector<int> values;
        int n;
        vector<int> expected;
    };

    const vector<TestCase> testCases = {
        {{1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}},
        {{1}, 1, {}},
        {{1, 2}, 1, {1}},
        {{1, 2}, 2, {2}},
        {{1, 2, 3}, 3, {2, 3}},
        {{1, 2, 3}, 1, {1, 2}},
        {{1, 2, 3, 4}, 2, {1, 2, 4}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        ListNode* head = buildList(testCases[i].values);
        head = solution.removeNthFromEnd(head, testCases[i].n);
        vector<int> actual = toVector(head);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyList(head);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
