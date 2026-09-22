#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 102. 二叉树的层序遍历
// BFS：每轮开始时，队列长度就是当前层的节点数。
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> level;

            while (size > 0) {
                TreeNode* node = nodes.front();
                nodes.pop();
                level.push_back(node->val);

                if (node->left != nullptr) nodes.push(node->left);
                if (node->right != nullptr) nodes.push(node->right);
                size--;
            }
            ans.push_back(level);
        }
        return ans;
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
    using Levels = vector<vector<int>>;
    const vector<pair<vector<optional<int>>, Levels>> testCases = {
        {{3, 9, 20, nullopt, nullopt, 15, 7}, {{3}, {9, 20}, {15, 7}}},
        {{1}, {{1}}},
        {{}, {}},
        {{1, 2, 3, 4, 5, 6, 7}, {{1}, {2, 3}, {4, 5, 6, 7}}},
        {{1, 2, nullopt, 3}, {{1}, {2}, {3}}},
        {{1, nullopt, 2, nullopt, 3}, {{1}, {2}, {3}}},
        {{0, -1, 2}, {{0}, {-1, 2}}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i].first);
        Levels actual = solution.levelOrder(root);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyTree(root);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
