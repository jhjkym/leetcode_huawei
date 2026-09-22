#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 199. 二叉树的右视图
// 层序遍历，每层最后一个出队的节点就是右视图节点。
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int size = nodes.size();
            while (size > 0) {
                TreeNode* node = nodes.front();
                nodes.pop();

                if (size == 1) ans.push_back(node->val);
                if (node->left != nullptr) nodes.push(node->left);
                if (node->right != nullptr) nodes.push(node->right);
                size--;
            }
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
    const vector<pair<vector<optional<int>>, vector<int>>> testCases = {
        {{1, 2, 3, nullopt, 5, nullopt, 4}, {1, 3, 4}},
        {{1, 2, 3, 4, nullopt, nullopt, nullopt, 5}, {1, 3, 4, 5}},
        {{1, nullopt, 3}, {1, 3}},
        {{}, {}},
        {{1}, {1}},
        {{1, 2, nullopt, 3, nullopt, 4}, {1, 2, 3, 4}},
        {{1, 2, 3, 4, 5, 6, 7}, {1, 3, 7}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i].first);
        vector<int> actual = solution.rightSideView(root);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyTree(root);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
