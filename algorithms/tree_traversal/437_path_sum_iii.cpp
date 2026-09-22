#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 437. 路径总和 III
// 前缀和 + DFS：prefix[sum - target] 是以当前节点结尾的合法路径数。
class Solution {
    unordered_map<long long, int> prefix;

public:
    int pathSum(TreeNode* root, int targetSum) {
        prefix.clear();
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }

private:
    int dfs(TreeNode* root, long long sum, int target) {
        if (root == nullptr) return 0;

        sum += root->val;
        int count = prefix[sum - target];

        prefix[sum]++;
        count += dfs(root->left, sum, target);
        count += dfs(root->right, sum, target);
        prefix[sum]--;

        return count;
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
        int target;
        int expected;
    };

    const vector<TestCase> testCases = {
        {{10, 5, -3, 3, 2, nullopt, 11, 3, -2, nullopt, 1}, 8, 3},
        {{5, 4, 8, 11, nullopt, 13, 4, 7, 2, nullopt, nullopt, 5, 1}, 22, 3},
        {{}, 0, 0},
        {{1}, 1, 1},
        {{1}, 0, 0},
        {{0, 0, 0}, 0, 5},
        {{1, -2, -3, 1, 3, -2, nullopt, -1}, -1, 4},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i].tree);
        int actual = solution.pathSum(root, testCases[i].target);
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
