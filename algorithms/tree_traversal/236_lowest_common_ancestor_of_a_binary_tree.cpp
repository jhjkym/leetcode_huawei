#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 236. 二叉树的最近公共祖先
// 左右子树都找到目标时，当前节点就是最近公共祖先。
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
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

TreeNode* findNode(TreeNode* root, int value) {
    if (root == nullptr || root->val == value) return root;
    TreeNode* left = findNode(root->left, value);
    return left != nullptr ? left : findNode(root->right, value);
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
        int p;
        int q;
        int expected;
    };

    const vector<TestCase> testCases = {
        {{3, 5, 1, 6, 2, 0, 8, nullopt, nullopt, 7, 4}, 5, 1, 3},
        {{3, 5, 1, 6, 2, 0, 8, nullopt, nullopt, 7, 4}, 5, 4, 5},
        {{1, 2}, 1, 2, 1},
        {{1, 2, 3}, 2, 3, 1},
        {{1, 2, nullopt, 3, nullopt, 4}, 3, 4, 3},
        {{1, 2, 3, 4, 5, 6, 7}, 4, 5, 2},
        {{1, 2, 3, 4, 5, 6, 7}, 4, 6, 1},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i].tree);
        TreeNode* p = findNode(root, testCases[i].p);
        TreeNode* q = findNode(root, testCases[i].q);
        TreeNode* actual = solution.lowestCommonAncestor(root, p, q);
        bool ok = actual != nullptr && actual->val == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << testCases[i].expected
             << "，实际 = " << (actual ? actual->val : -1) << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
        destroyTree(root);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
