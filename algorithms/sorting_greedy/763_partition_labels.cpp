#include <bits/stdc++.h>
using namespace std;

// 763. 划分字母区间
// 扫描时不断扩展当前区间的最远边界，到达边界就完成一次划分。
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26]{};
        int n = s.size();
        for (int i = 0; i < n; ++i) last[s[i] - 'a'] = i;

        vector<int> ans;
        int start = 0;
        int end = 0;

        for (int i = 0; i < n; ++i) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};

int main() {
    const vector<pair<string, vector<int>>> testCases = {
        {"ababcbacadefegdehijhklij", {9, 7, 8}},
        {"eccbbbbdec", {10}},
        {"a", {1}},
        {"abc", {1, 1, 1}},
        {"aaaa", {4}},
        {"abaccbdeffed", {6, 6}},
        {"caedbdedda", {1, 9}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> actual = solution.partitionLabels(testCases[i].first);
        bool ok = actual == testCases[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
