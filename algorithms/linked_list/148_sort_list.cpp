#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 148. 排序链表
// 归并排序：快慢指针切成两半，分别排序后合并。
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        right = sortList(right);
        return merge(left, right);
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
    const vector<pair<vector<int>, vector<int>>> testCases = {
        {{4, 2, 1, 3}, {1, 2, 3, 4}},
        {{-1, 5, 3, 4, 0}, {-1, 0, 3, 4, 5}},
        {{}, {}},
        {{1}, {1}},
        {{2, 1}, {1, 2}},
        {{3, 3, 1, 2, 1}, {1, 1, 2, 3, 3}},
        {{5, 4, 3, 2, 1}, {1, 2, 3, 4, 5}},
        {{1, 2, 3, 4}, {1, 2, 3, 4}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        ListNode* head = buildList(testCases[i].first);
        head = solution.sortList(head);
        vector<int> actual = toVector(head);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyList(head);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
