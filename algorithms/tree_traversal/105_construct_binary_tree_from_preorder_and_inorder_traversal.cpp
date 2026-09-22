#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 105. 从前序与中序遍历序列构造二叉树
// 前序确定根节点，中序确定左右子树范围。
class Solution {
    unordered_map<int, int> position;
    int preorderIndex = 0;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        position.clear();
        preorderIndex = 0;
        int n = inorder.size();
        for (int i = 0; i < n; ++i) position[inorder[i]] = i;
        return build(preorder, 0, n - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        int mid = position[rootValue];

        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);
        return root;
    }
};

void preorderTraversal(TreeNode* root, vector<int>& values) {
    if (root == nullptr) return;
    values.push_back(root->val);
    preorderTraversal(root->left, values);
    preorderTraversal(root->right, values);
}

void inorderTraversal(TreeNode* root, vector<int>& values) {
    if (root == nullptr) return;
    inorderTraversal(root->left, values);
    values.push_back(root->val);
    inorderTraversal(root->right, values);
}

void destroyTree(TreeNode* root) {
    if (root == nullptr) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main() {
    struct TestCase {
        vector<int> preorder;
        vector<int> inorder;
    };

    const vector<TestCase> testCases = {
        {{3, 9, 20, 15, 7}, {9, 3, 15, 20, 7}},
        {{-1}, {-1}},
        {{}, {}},
        {{1, 2, 3}, {3, 2, 1}},
        {{1, 2, 3}, {1, 2, 3}},
        {{1, 2, 4, 5, 3, 6, 7}, {4, 2, 5, 1, 6, 3, 7}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> preorder = testCases[i].preorder;
        vector<int> inorder = testCases[i].inorder;
        TreeNode* root = solution.buildTree(preorder, inorder);

        vector<int> actualPreorder;
        vector<int> actualInorder;
        preorderTraversal(root, actualPreorder);
        inorderTraversal(root, actualInorder);
        bool ok = actualPreorder == preorder && actualInorder == inorder;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyTree(root);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
