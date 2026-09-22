#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 543. 二叉树的直径
// 求深度时，用“左深度 + 右深度”更新经过当前节点的直径。
class Solution {
    int ans = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        depth(root);
        return ans;
    }

private:
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = depth(root->left);
        int right = depth(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
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
        {{1, 2, 3, 4, 5}, 3},
        {{1, 2}, 1},
        {{1}, 0},
        {{}, 0},
        {{1, 2, 3, 4, 5, nullopt, nullopt, 6, 7}, 4},
        {{1, 2, nullopt, 3, nullopt, 4}, 3},
        {{1, 2, 3, 4, nullopt, nullopt, 5}, 4},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i].first);
        int actual = solution.diameterOfBinaryTree(root);
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
