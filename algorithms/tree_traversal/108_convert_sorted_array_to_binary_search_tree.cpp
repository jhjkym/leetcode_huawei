#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 108. 将有序数组转换为二叉搜索树
// 每次选择区间中点作为根节点，递归构造左右子树。
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return build(nums, 0, n - 1);
    }

private:
    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, left, mid - 1);
        root->right = build(nums, mid + 1, right);
        return root;
    }
};

void inorder(TreeNode* root, vector<int>& values) {
    if (root == nullptr) return;
    inorder(root->left, values);
    values.push_back(root->val);
    inorder(root->right, values);
}

int checkHeight(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = checkHeight(root->left);
    int right = checkHeight(root->right);
    if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
    return max(left, right) + 1;
}

void destroyTree(TreeNode* root) {
    if (root == nullptr) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main() {
    const vector<vector<int>> testCases = {
        {-10, -3, 0, 5, 9},
        {1, 3},
        {},
        {1},
        {1, 2, 3, 4},
        {-5, -4, -3, -2, -1, 0, 1},
        {1, 2, 3, 4, 5, 6, 7},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i];
        TreeNode* root = solution.sortedArrayToBST(nums);
        vector<int> actual;
        inorder(root, actual);
        bool ok = actual == nums && checkHeight(root) != -1;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
        destroyTree(root);
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
