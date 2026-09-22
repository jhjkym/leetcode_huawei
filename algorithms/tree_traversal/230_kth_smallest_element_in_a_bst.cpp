#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 230. 二叉搜索树中第 K 小的元素
// BST 的中序遍历是升序，第 k 个访问的节点就是答案。
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> nodes;

        while (root != nullptr || !nodes.empty()) {
            while (root != nullptr) {
                nodes.push(root);
                root = root->left;
            }

            root = nodes.top();
            nodes.pop();
            k--;
            if (k == 0) return root->val;

            root = root->right;
        }
        return -1;
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
        int k;
        int expected;
    };

    const vector<TestCase> testCases = {
        {{3, 1, 4, nullopt, 2}, 1, 1},
        {{5, 3, 6, 2, 4, nullopt, nullopt, 1}, 3, 3},
        {{2, 1, 3}, 2, 2},
        {{1}, 1, 1},
        {{4, 2, 6, 1, 3, 5, 7}, 7, 7},
        {{0, -2, 3, -3, -1, 2, 4}, 4, 0},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i].tree);
        int actual = solution.kthSmallest(root, testCases[i].k);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << testCases[i].expected
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
        destroyTree(root);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
