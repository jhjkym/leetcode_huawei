#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 101. 对称二叉树
// 同时比较左右子树：外侧对外侧，内侧对内侧。
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        if (left->val != right->val) return false;

        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
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

void destroyTree(TreeNode* root) {
    if (root == nullptr) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main() {
    const vector<pair<vector<optional<int>>, bool>> testCases = {
        {{1, 2, 2, 3, 4, 4, 3}, true},
        {{1, 2, 2, nullopt, 3, nullopt, 3}, false},
        {{}, true},
        {{1}, true},
        {{1, 2, 2, nullopt, 3, 3, nullopt}, true},
        {{1, 2, 2, 3, nullopt, 3, nullopt}, false},
        {{1, 2, 3}, false},
        {{0, -1, -1}, true},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i].first);
        bool actual = solution.isSymmetric(root);
        bool expected = testCases[i].second;
        bool ok = actual == expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << boolalpha << expected
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
        destroyTree(root);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
