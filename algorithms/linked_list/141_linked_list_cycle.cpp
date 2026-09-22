#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 141. 环形链表
// Floyd 判圈：慢指针走一步，快指针走两步；相遇则有环。
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

ListNode* buildList(const vector<int>& values, int pos,
                    vector<ListNode*>& nodes) {
    for (int value : values) nodes.push_back(new ListNode(value));
    for (size_t i = 1; i < nodes.size(); ++i) {
        nodes[i - 1]->next = nodes[i];
    }
    if (!nodes.empty() && pos >= 0) nodes.back()->next = nodes[pos];
    return nodes.empty() ? nullptr : nodes[0];
}

int main() {
    struct TestCase {
        vector<int> values;
        int pos;
        bool expected;
    };

    const vector<TestCase> testCases = {
        {{3, 2, 0, -4}, 1, true},
        {{1, 2}, 0, true},
        {{1}, -1, false},
        {{1}, 0, true},
        {{1, 2, 3, 4}, 3, true},
        {{1, 2, 3, 4}, -1, false},
        {{}, -1, false},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<ListNode*> nodes;
        ListNode* head = buildList(testCases[i].values, testCases[i].pos, nodes);
        bool actual = solution.hasCycle(head);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << boolalpha
             << testCases[i].expected << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
        for (ListNode* node : nodes) delete node;
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
