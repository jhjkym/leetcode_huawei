#include <bits/stdc++.h>
using namespace std;

// 226. 翻转二叉树
// 递归交换每个节点的左右子树。

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

TreeNode* buildTree(const vector<optional<int>>& values) {
    if (values.empty() || !values[0].has_value()) return nullptr;
    vector<TreeNode*> nodes;
    for (const auto& value : values) {
        nodes.push_back(value.has_value() ? new TreeNode(*value) : nullptr);
    }
    size_t child = 1;
    for (TreeNode* node : nodes) {
        if (node == nullptr) continue;
        if (child < nodes.size()) node->left = nodes[child++];
        if (child < nodes.size()) node->right = nodes[child++];
    }
    return nodes[0];
}

vector<optional<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    vector<optional<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node == nullptr) {
            result.push_back(nullopt);
            continue;
        }
        result.push_back(node->val);
        q.push(node->left);
        q.push(node->right);
    }
    while (!result.empty() && !result.back().has_value()) result.pop_back();
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestCase {
        vector<optional<int>> input;
        vector<optional<int>> expected;
    };
    const vector<TestCase> testCases = {
        {{4, 2, 7, 1, 3, 6, 9}, {4, 7, 2, 9, 6, 3, 1}},
        {{2, 1, 3}, {2, 3, 1}},
        {{}, {}},
        {{1}, {1}},
        {{1, 2}, {1, nullopt, 2}},
        {{1, nullopt, 2}, {1, 2}},
        {{1, 2, 3, 4, nullopt, nullopt, 5}, {1, 3, 2, 5, nullopt, nullopt, 4}},
        {{-1, -2, -3}, {-1, -3, -2}},
        {{0, -1, 1, -2, nullopt, nullopt, 2}, {0, 1, -1, 2, nullopt, nullopt, -2}},
        {{5, 3, 8, 1, 4, 7, 9}, {5, 8, 3, 9, 7, 4, 1}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i].input);
        TreeNode* actualRoot = solution.invertTree(root);
        auto actual = levelOrder(actualRoot);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": 预期 = [";
        for (size_t j = 0; j < testCases[i].expected.size(); ++j) {
            if (j > 0) cout << ", ";
            if (testCases[i].expected[j].has_value()) cout << *testCases[i].expected[j];
            else cout << "null";
        }
        cout << "]，实际 = [";
        for (size_t j = 0; j < actual.size(); ++j) {
            if (j > 0) cout << ", ";
            if (actual[j].has_value()) cout << *actual[j];
            else cout << "null";
        }
        cout << "]，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
