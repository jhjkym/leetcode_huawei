#include <bits/stdc++.h>
using namespace std;

// 49. 字母异位词分组
// 异位词排序后得到的字符串相同，因此可以用排序结果作为哈希表的 key。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            groups[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& [key, words] : groups) {
            result.push_back(words);
        }
        return result;
    }
};

static vector<vector<string>> normalize(vector<vector<string>> groups) {
    for (auto& group : groups) sort(group.begin(), group.end());
    sort(groups.begin(), groups.end());
    return groups;
}

int main() {
    const vector<pair<vector<string>, vector<vector<string>>>> testCases = {
        {{"eat", "tea", "tan", "ate", "nat", "bat"},
         {{"ate", "eat", "tea"}, {"nat", "tan"}, {"bat"}}},
        {{""}, {{""}}},
        {{"a"}, {{"a"}}},
        {{"abc", "bca", "cab", "dog"}, {{"abc", "bca", "cab"}, {"dog"}}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<string> input = testCases[i].first;
        bool ok = normalize(solution.groupAnagrams(input)) == normalize(testCases[i].second);
        passed += ok;
        cout << "用例 " << i + 1 << "：" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
