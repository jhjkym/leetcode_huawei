#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 142. 环形链表 II
// 快慢指针相遇后，一个指针回到头节点；两者再同步走，相遇点就是环入口。
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode* cur = head;
                while (cur != slow) {
                    cur = cur->next;
                    slow = slow->next;
                }
                return cur;
            }
        }
        return nullptr;
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
    };

    const vector<TestCase> testCases = {
        {{3, 2, 0, -4}, 1},
        {{1, 2}, 0},
        {{1}, -1},
        {{1}, 0},
        {{1, 2, 3, 4}, 3},
        {{1, 2, 3, 4, 5}, 2},
        {{1, 2, 3}, -1},
        {{}, -1},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<ListNode*> nodes;
        ListNode* head = buildList(testCases[i].values, testCases[i].pos, nodes);
        ListNode* expected = testCases[i].pos < 0
                                 ? nullptr
                                 : nodes[testCases[i].pos];
        ListNode* actual = solution.detectCycle(head);
        bool ok = actual == expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期入口 = " << testCases[i].pos
             << "，实际节点值 = " << (actual ? actual->val : -1)
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
        for (ListNode* node : nodes) delete node;
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
