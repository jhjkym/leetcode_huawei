#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 98. 验证二叉搜索树
// 每个节点都必须严格位于祖先传下来的上下界之间。
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool isValid(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) return true;
        if (root->val <= lower || root->val >= upper) return false;

        return isValid(root->left, lower, root->val) &&
               isValid(root->right, root->val, upper);
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
        {{2, 1, 3}, true},
        {{5, 1, 4, nullopt, nullopt, 3, 6}, false},
        {{}, true},
        {{1}, true},
        {{2, 2, 2}, false},
        {{5, 4, 6, nullopt, nullopt, 3, 7}, false},
        {{10, 5, 15, nullopt, nullopt, 11, 20}, true},
        {{INT_MIN, nullopt, INT_MAX}, true},
        {{0, INT_MIN, INT_MAX}, true},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i].first);
        bool actual = solution.isValidBST(root);
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
