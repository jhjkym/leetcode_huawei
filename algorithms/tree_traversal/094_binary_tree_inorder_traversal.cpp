#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 94. 二叉树的中序遍历
// 中序顺序：左子树 -> 根节点 -> 右子树。
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

private:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
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
    struct TestCase {
        vector<optional<int>> tree;
        vector<int> expected;
    };

    const vector<TestCase> testCases = {
        {{1, nullopt, 2, 3}, {1, 3, 2}},
        {{1, 2, 3, 4, 5, nullopt, 8}, {4, 2, 5, 1, 3, 8}},
        {{}, {}},
        {{1}, {1}},
        {{2, 1, 3}, {1, 2, 3}},
        {{1, 2, nullopt, 3}, {3, 2, 1}},
        {{1, nullopt, 2, nullopt, 3}, {1, 2, 3}},
        {{0, -1, 2}, {-1, 0, 2}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i].tree);
        vector<int> actual = solution.inorderTraversal(root);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyTree(root);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
