#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

// 138. 随机链表的复制
// 两遍哈希表：第一遍复制节点，第二遍连接 next 和 random。
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> copy;
        for (Node* cur = head; cur != nullptr; cur = cur->next) {
            copy[cur] = new Node(cur->val);
        }

        for (Node* cur = head; cur != nullptr; cur = cur->next) {
            copy[cur]->next = copy[cur->next];
            copy[cur]->random = copy[cur->random];
        }
        return copy[head];
    }
};

Node* buildList(const vector<int>& values, const vector<int>& randomIndex) {
    vector<Node*> nodes;
    for (int value : values) nodes.push_back(new Node(value));
    for (size_t i = 1; i < nodes.size(); ++i) nodes[i - 1]->next = nodes[i];
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (randomIndex[i] >= 0) nodes[i]->random = nodes[randomIndex[i]];
    }
    return nodes.empty() ? nullptr : nodes[0];
}

vector<pair<int, int>> serialize(Node* head) {
    vector<Node*> nodes;
    unordered_map<Node*, int> index;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        index[cur] = nodes.size();
        nodes.push_back(cur);
    }

    vector<pair<int, int>> result;
    for (Node* node : nodes) {
        int randomIndex = node->random == nullptr ? -1 : index[node->random];
        result.push_back({node->val, randomIndex});
    }
    return result;
}

bool isDeepCopy(Node* original, Node* copied) {
    unordered_set<Node*> originalNodes;
    for (Node* cur = original; cur != nullptr; cur = cur->next) {
        originalNodes.insert(cur);
    }
    for (Node* cur = copied; cur != nullptr; cur = cur->next) {
        if (originalNodes.count(cur)) return false;
    }
    return serialize(original) == serialize(copied);
}

void destroyList(Node* head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    struct TestCase {
        vector<int> values;
        vector<int> randomIndex;
    };

    const vector<TestCase> testCases = {
        {{7, 13, 11, 10, 1}, {-1, 0, 4, 2, 0}},
        {{1, 2}, {1, 1}},
        {{3, 3, 3}, {1, 2, 0}},
        {{1}, {0}},
        {{1}, {-1}},
        {{}, {}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        Node* original = buildList(testCases[i].values, testCases[i].randomIndex);
        Node* copied = solution.copyRandomList(original);
        bool ok = isDeepCopy(original, copied);
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyList(original);
        destroyList(copied);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
