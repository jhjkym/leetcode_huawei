#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 114. 二叉树展开为链表
// 反向前序遍历：先右、再左，用 previous 连接已经展开的链表。
class Solution {
    TreeNode* previous = nullptr;

public:
    void flatten(TreeNode* root) {
        previous = nullptr;
        flattenTree(root);
    }

private:
    void flattenTree(TreeNode* root) {
        if (root == nullptr) return;

        flattenTree(root->right);
        flattenTree(root->left);
        root->right = previous;
        root->left = nullptr;
        previous = root;
    }
};

TreeNode* buildTree(const vector<optional<int>>& values) {
    if (values.empty() || !values[0].has_value()) return nullptr;

    TreeNode* root = new TreeNode(*values[0]);
    queue<TreeNode*> nodes;
    nodes.push(root);
    size_t i = 1;

    while (!nodes.empty() && i < values.size()) {
        TreeNode* node = nodes.front();
        nodes.pop();

        if (i < values.size() && values[i].has_value()) {
            node->left = new TreeNode(*values[i]);
            nodes.push(node->left);
        }
        i++;

        if (i < values.size() && values[i].has_value()) {
            node->right = new TreeNode(*values[i]);
            nodes.push(node->right);
        }
        i++;
    }
    return root;
}

pair<vector<int>, bool> readFlattened(TreeNode* root) {
    vector<int> values;
    bool allLeftNull = true;
    while (root != nullptr) {
        values.push_back(root->val);
        if (root->left != nullptr) allLeftNull = false;
        root = root->right;
    }
    return {values, allLeftNull};
}

void destroyTree(TreeNode* root) {
    if (root == nullptr) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main() {
    struct TestCase {
        vector<optional<int>> tree;
        vector<int> expected;
    };

    const vector<TestCase> testCases = {
        {{1, 2, 5, 3, 4, nullopt, 6}, {1, 2, 3, 4, 5, 6}},
        {{}, {}},
        {{0}, {0}},
        {{1, 2, nullopt, 3}, {1, 2, 3}},
        {{1, nullopt, 2, nullopt, 3}, {1, 2, 3}},
        {{1, 2, 3, 4, 5, 6, 7}, {1, 2, 4, 5, 3, 6, 7}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i].tree);
        solution.flatten(root);
        auto [actual, allLeftNull] = readFlattened(root);
        bool ok = actual == testCases[i].expected && allLeftNull;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyTree(root);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
