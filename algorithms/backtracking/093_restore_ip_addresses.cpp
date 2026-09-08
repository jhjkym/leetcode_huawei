#include <bits/stdc++.h>
using namespace std;

// 93. 复原 IP 地址
// 算法：回溯（分割型）；数据结构：路径段数组、字符串。
// 在纯数字字符串中插入三个点，返回所有合法 IP 地址。
// 直接运行即可执行 main 中的固定测例。
// 背诵模板：分割回溯 + 段数剪枝 + 合法段判断（长度、前导零、<=255）。
// 掌握状态：不会，待复习背诵。
//
// 四步口诀：
//   1. 出口：已切 4 段且刚好用完所有字符才收集，段够了但没用完要丢弃；
//   2. 每层枚举本段长度 1~3，超出字符串末尾就 break；
//   3. isValid 三查：前导零、数值 <= 255（长度由枚举范围保证）；
//   4. push 后递归，回来 pop_back 撤销（标准回溯三部曲）。

class Solution {
public:
    // 判断一段是否是合法的 IP 段。
    // 三个条件：非空、无前导零（"0" 本身合法但 "01" 不合法）、数值不超过 255。
    // 长度不超过 3 由调用处的枚举范围保证，这里再判一次更保险。
    bool isValid(const string& segment) {
        if (segment.empty() || segment.size() > 3) {
            return false;
        }
        // 前导零：长度大于 1 却以 '0' 开头，如 "01"、"00"。
        if (segment.size() > 1 && segment[0] == '0') {
            return false;
        }
        // 长度最多 3，最大 "999"，用 int 转换不会溢出。
        return stoi(segment) <= 255;
    }

    // start：本段从哪个下标开始切；path：已经切好的段。
    void backtracking(const string& s, int start, vector<string>& path,
                      vector<string>& ans) {
        // 出口：已经切满 4 段。
        if (path.size() == 4) {
            // 必须同时用完所有字符，否则是「4 段没覆盖全串」的非法方案，直接丢弃。
            if (start == static_cast<int>(s.size())) {
                // 用 '.' 把四段拼起来。
                ans.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            }
            return;
        }

        // 枚举本段长度 1、2、3。
        for (int len = 1; len <= 3; ++len) {
            // 越过末尾就不必再试更长的了，直接 break。
            if (start + len > static_cast<int>(s.size())) {
                break;
            }

            const string segment = s.substr(start, len);
            if (!isValid(segment)) {
                // 注意用 continue 而不是 break：长度 1 非法不代表长度 2、3 也非法。
                // 反例：以 '0' 开头时 "0" 合法而 "01" 不合法，顺序相反同理。
                continue;
            }

            // 回溯三部曲：选择、递归、撤销。
            path.push_back(segment);
            backtracking(s, start + len, path, ans);
            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> path;
        // 长度剪枝：4 段每段最多 3 位、最少 1 位，长度不在 [4, 12] 内必然无解。
        if (s.size() < 4 || s.size() > 12) {
            return ans;
        }
        backtracking(s, 0, path, ans);
        return ans;
    }
};

static vector<string> normalize(vector<string> addresses) {
    sort(addresses.begin(), addresses.end());
    return addresses;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<string, vector<string>>> testCases = {
        {"25525511135", {"255.255.11.135", "255.255.111.35"}},
        {"0000", {"0.0.0.0"}},
        {"101023",
         {"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"}},
        {"1111", {"1.1.1.1"}},
        {"010010", {"0.10.0.10", "0.100.1.0"}},
        {"1", {}},
        {"255255255255", {"255.255.255.255"}},
        {"00000", {}},
        {"000256", {}},
        {"2552552550", {"255.255.25.50", "255.255.255.0"}},
        {"19216811",
         {"1.92.168.11", "19.2.168.11", "19.21.68.11", "19.216.8.11",
          "19.216.81.1", "192.1.68.11", "192.16.8.11", "192.16.81.1",
          "192.168.1.1"}},
        {"1212122",
         {"1.2.12.122", "1.2.121.22", "1.21.2.122", "1.21.21.22", "1.21.212.2",
          "1.212.1.22", "1.212.12.2", "12.1.2.122", "12.1.21.22", "12.1.212.2",
          "12.12.1.22", "12.12.12.2", "12.121.2.2", "121.2.1.22", "121.2.12.2",
          "121.21.2.2"}},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const string& input = testCases[i].first;
        const auto expected = normalize(testCases[i].second);
        const auto actual = normalize(solution.restoreIpAddresses(input));
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": s = " << quoted(input)
             << "，预期个数 = " << expected.size()
             << "，实际个数 = " << actual.size()
             << "，" << (ok ? "PASS" : "FAIL") << '\n';
        if (!ok) {
            cout << "  预期 =";
            for (const string& item : expected) cout << ' ' << item;
            cout << "\n  实际 =";
            for (const string& item : actual) cout << ' ' << item;
            cout << '\n';
        }
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
