#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 21. 合并两个有序链表
// 哑节点统一处理头节点，尾指针始终指向合并链表的末尾。
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = list1 != nullptr ? list1 : list2;
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
        vector<int> list1;
        vector<int> list2;
        vector<int> expected;
    };

    const vector<TestCase> testCases = {
        {{1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4}},
        {{}, {}, {}},
        {{}, {0}, {0}},
        {{1}, {}, {1}},
        {{-3, -1, 2}, {-2, 0, 3}, {-3, -2, -1, 0, 2, 3}},
        {{1, 1, 1}, {1, 1}, {1, 1, 1, 1, 1}},
        {{1, 2}, {3, 4}, {1, 2, 3, 4}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        ListNode* list1 = buildList(testCases[i].list1);
        ListNode* list2 = buildList(testCases[i].list2);
        ListNode* merged = solution.mergeTwoLists(list1, list2);
        vector<int> actual = toVector(merged);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyList(merged);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
