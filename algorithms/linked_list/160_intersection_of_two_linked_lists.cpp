#include <bits/stdc++.h>
using namespace std;

// 160. 相交链表
// 返回两个单链表相交的第一个节点；相交指两个指针指向同一个节点，而不是数值相同。
// 掌握状态：已完成，双指针细节待复习。

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 != p2) {
            p1 = p1 ? p1->next : headB;
            p2 = p2 ? p2->next : headA;
        }
        return p1;
    }
};

ListNode* build(const vector<int>& values) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }
    return dummy.next;
}

void append(ListNode* head, ListNode* suffix) {
    if (head == nullptr) return;
    while (head->next != nullptr) head = head->next;
    head->next = suffix;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        vector<int> valuesA;
        vector<int> valuesB;
        vector<int> common;
        bool shouldIntersect;
    };
    const vector<TestCase> testCases = {
        {{4, 1}, {5, 6, 1}, {8, 4, 5}, true},
        {{1, 9}, {3}, {}, false},
        {{2}, {2}, {7}, true},
        {{}, {1, 2}, {}, false},
        {{1, 2}, {}, {}, false},
        {{1}, {2}, {3}, true},
        {{1, 2, 3}, {4, 5}, {6, 7, 8}, true},
        {{1, 2, 3}, {4, 5, 6}, {}, false},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        ListNode* common = build(testCase.common);
        ListNode* headA = build(testCase.valuesA);
        ListNode* headB = build(testCase.valuesB);
        append(headA, common);
        append(headB, common);
        ListNode* actual = solution.getIntersectionNode(headA, headB);
        bool ok = testCase.shouldIntersect ? actual == common : actual == nullptr;
        passed += ok;
        cout << "用例 " << i + 1 << ": 预期相交 = " << boolalpha
             << testCase.shouldIntersect << "，实际 = " << (actual != nullptr)
             << "，相交节点值 = " << (actual == nullptr ? -1 : actual->val)
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
