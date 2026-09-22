#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 234. 回文链表
// 快慢指针找中点，反转后半段，再从两端开始比较。
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = reverseList(slow);
        ListNode* left = head;
        while (right != nullptr) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

ListNode* buildList(const vector<int>& values, vector<ListNode*>& nodes) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
        nodes.push_back(tail);
    }
    return dummy.next;
}

int main() {
    const vector<pair<vector<int>, bool>> testCases = {
        {{1, 2, 2, 1}, true},
        {{1, 2}, false},
        {{1, 2, 3, 2, 1}, true},
        {{1, 2, 3, 1}, false},
        {{1}, true},
        {{1, 1}, true},
        {{}, true},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<ListNode*> nodes;
        ListNode* head = buildList(testCases[i].first, nodes);
        bool actual = solution.isPalindrome(head);
        bool expected = testCases[i].second;
        bool ok = actual == expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << boolalpha << expected
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
        for (ListNode* node : nodes) delete node;
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
