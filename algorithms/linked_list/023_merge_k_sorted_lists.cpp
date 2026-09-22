#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 23. 合并 K 个升序链表
// 两两归并：每轮合并间隔为 1、2、4、8... 的链表。
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        for (int step = 1; step < n; step *= 2) {
            for (int i = 0; i + step < n; i += step * 2) {
                lists[i] = merge(lists[i], lists[i + step]);
            }
        }
        return n == 0 ? nullptr : lists[0];
    }

private:
    ListNode* merge(ListNode* list1, ListNode* list2) {
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
        vector<vector<int>> lists;
        vector<int> expected;
    };

    const vector<TestCase> testCases = {
        {{{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6}},
        {{}, {}},
        {{{}}, {}},
        {{{1}}, {1}},
        {{{-3, -1, 2}, {-2, 0, 3}}, {-3, -2, -1, 0, 2, 3}},
        {{{1, 1}, {1}, {1, 1, 1}}, {1, 1, 1, 1, 1, 1}},
        {{{}, {1, 3}, {}, {2, 4}}, {1, 2, 3, 4}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<ListNode*> lists;
        for (const vector<int>& values : testCases[i].lists) {
            lists.push_back(buildList(values));
        }
        ListNode* merged = solution.mergeKLists(lists);
        vector<int> actual = toVector(merged);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyList(merged);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
