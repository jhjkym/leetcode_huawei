#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 25. K 个一组翻转链表
// 每次找到一组的第 k 个节点，只翻转长度完整的分组。
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            if (kth == nullptr) break;
            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* cur = groupPrev->next;
            while (cur != groupNext) {
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

            ListNode* groupFirst = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = groupFirst;
        }
        return dummy.next;
    }

private:
    ListNode* getKth(ListNode* cur, int k) {
        while (cur != nullptr && k > 0) {
            cur = cur->next;
            k--;
        }
        return cur;
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
        int k;
        vector<int> expected;
    };

    const vector<TestCase> testCases = {
        {{1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5}},
        {{1, 2, 3, 4, 5}, 3, {3, 2, 1, 4, 5}},
        {{1, 2, 3, 4}, 4, {4, 3, 2, 1}},
        {{1, 2, 3, 4}, 1, {1, 2, 3, 4}},
        {{1, 2}, 3, {1, 2}},
        {{1}, 1, {1}},
        {{}, 2, {}},
        {{1, 2, 3, 4, 5, 6}, 3, {3, 2, 1, 6, 5, 4}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        ListNode* head = buildList(testCases[i].values);
        head = solution.reverseKGroup(head, testCases[i].k);
        vector<int> actual = toVector(head);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyList(head);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
