#include <bits/stdc++.h>
using namespace std;

// 179. 最大数
// 算法：贪心 + 自定义排序比较器；数据结构：字符串数组。
// 把一组非负整数重排拼接，返回能组成的最大整数（字符串形式）。
// 直接运行即可执行 main 中的固定测例。
// 背诵模板：转字符串 + 比较器 a + b > b + a + 全零特判。
// 掌握状态：不会，待复习背诵。
//
// 三步口诀：
//   1. int 全部转成 string；
//   2. sort 时比较「拼接结果」：a + b > b + a 则 a 在前；
//   3. 拼接，若首字符是 '0' 则整体返回 "0"。

class Solution {
public:
    // 比较器：a 排在 b 前面的条件。
    // 比的不是 a 和 b 本身，而是两种拼接顺序谁更大。
    // 例 a="3", b="30"：a+b="330" > b+a="303"，所以 3 排在 30 前面。
    // 因为 a+b 与 b+a 长度相同，字符串字典序比较等价于数值比较。
    // 必须用严格 >：写成 >= 会破坏严格弱序，sort 可能越界。
    // 需要声明为 static，才能作为普通函数指针传给 sort。
    static bool cmp(const string& a, const string& b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        // 第 1 步：转字符串。后面只做拼接比较，避免任何整型溢出。
        vector<string> strs;
        strs.reserve(nums.size());
        for (int num : nums) {
            strs.push_back(to_string(num));
        }

        // 第 2 步：用自定义比较器排序，规则见上面的 cmp。
        sort(strs.begin(), strs.end(), cmp);

        // 第 3 步：按序拼接。
        string ans;
        for (const string& s : strs) {
            ans += s;
        }

        // 全零特判：排序后最大的一项仍是 '0' 开头，说明全是 0，
        // 此时 ans 形如 "000"，必须归一化为 "0"。
        // 注意 [0,0,0,1] 排序后是 "1000"，首字符为 '1'，不会被这里误判。
        if (ans[0] == '0') {
            return "0";
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<vector<int>, string>> testCases = {
        {{10, 2}, "210"},
        {{3, 30, 34, 5, 9}, "9534330"},
        {{1}, "1"},
        {{10}, "10"},
        {{0, 0}, "0"},
        {{0, 0, 0, 1}, "1000"},
        {{432, 43, 4321}, "434324321"},
        {{121, 12}, "12121"},
        {{12, 121}, "12121"},
        {{824, 8247}, "8248247"},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}, "987654321"},
        {{999999998, 999999997, 999999999}, "999999999999999998999999997"},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto nums = testCases[i].first;
        const string& expected = testCases[i].second;
        const string actual = solution.largestNumber(nums);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": nums = [";
        for (size_t j = 0; j < nums.size(); ++j) {
            if (j) cout << ", ";
            cout << nums[j];
        }
        cout << "]，预期 = " << expected
             << "，实际 = " << actual
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
