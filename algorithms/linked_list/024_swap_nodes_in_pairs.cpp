#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 24. 两两交换链表中的节点
// cur 指向每一对节点的前驱，通过修改三个 next 完成交换。
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = &dummy;

        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* first = cur->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            cur->next = second;

            cur = first;
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
    const vector<pair<vector<int>, vector<int>>> testCases = {
        {{1, 2, 3, 4}, {2, 1, 4, 3}},
        {{}, {}},
        {{1}, {1}},
        {{1, 2, 3}, {2, 1, 3}},
        {{1, 2}, {2, 1}},
        {{1, 2, 3, 4, 5}, {2, 1, 4, 3, 5}},
        {{-1, 0, 1, 2}, {0, -1, 2, 1}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        ListNode* head = buildList(testCases[i].first);
        head = solution.swapPairs(head);
        vector<int> actual = toVector(head);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyList(head);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
