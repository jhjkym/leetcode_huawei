#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 2. 两数相加
// 同时遍历两条链表，当前位取模，进位整除 10。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            carry = sum / 10;
        }
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
        vector<int> l1;
        vector<int> l2;
        vector<int> expected;
    };

    const vector<TestCase> testCases = {
        {{2, 4, 3}, {5, 6, 4}, {7, 0, 8}},
        {{0}, {0}, {0}},
        {{9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9},
         {8, 9, 9, 9, 0, 0, 0, 1}},
        {{1}, {9, 9}, {0, 0, 1}},
        {{5}, {5}, {0, 1}},
        {{1, 8}, {0}, {1, 8}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        ListNode* l1 = buildList(testCases[i].l1);
        ListNode* l2 = buildList(testCases[i].l2);
        ListNode* result = solution.addTwoNumbers(l1, l2);
        vector<int> actual = toVector(result);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyList(l1);
        destroyList(l2);
        destroyList(result);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
