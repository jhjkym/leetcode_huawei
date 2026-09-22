#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 124. 二叉树中的最大路径和
// 返回向下的最大贡献，同时用左右贡献更新完整路径答案。
class Solution {
    int ans = INT_MIN;

public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        gain(root);
        return ans;
    }

private:
    int gain(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = max(0, gain(root->left));
        int right = max(0, gain(root->right));
        ans = max(ans, root->val + left + right);

        return root->val + max(left, right);
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
    const vector<pair<vector<optional<int>>, int>> testCases = {
        {{1, 2, 3}, 6},
        {{-10, 9, 20, nullopt, nullopt, 15, 7}, 42},
        {{-3}, -3},
        {{2, -1}, 2},
        {{-2, -1}, -1},
        {{5, 4, 8, 11, nullopt, 13, 4, 7, 2, nullopt, nullopt, nullopt, 1}, 48},
        {{1, -2, -3, 1, 3, -2, nullopt, -1}, 3},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i].first);
        int actual = solution.maxPathSum(root);
        int expected = testCases[i].second;
        bool ok = actual == expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << expected
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
        destroyTree(root);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
