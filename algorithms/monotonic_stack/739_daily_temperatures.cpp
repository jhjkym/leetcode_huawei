#include <bits/stdc++.h>
using namespace std;

// 739. 每日温度
// 算法：单调栈；数据结构：栈、数组。
// 返回每天需要等待多少天才会有更高温度；没有更高温度则为 0。
// 直接运行即可执行 main 中的固定测例。

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(),0);
        for(int i = 0;i < temperatures.size();i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int j = st.top();
                st.pop();
                ans[j] = i -j;
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<vector<int>, vector<int>>> testCases = {
        {{73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0}},
        {{30, 40, 50, 60}, {1, 1, 1, 0}},
        {{30, 60, 90}, {1, 1, 0}},
        {{70}, {0}},
        {{70, 70, 70}, {0, 0, 0}},
        {{90, 80, 70, 60}, {0, 0, 0, 0}},
        {{70, 70, 71}, {2, 1, 0}},
        {{71, 70, 70}, {0, 0, 0}},
        {{70, 71, 70, 72}, {1, 2, 1, 0}},
        {{60, 50, 40, 70}, {3, 2, 1, 0}},
        {{30, 100, 30, 100}, {1, 0, 1, 0}},
        {{70, 60, 70, 60, 70}, {0, 1, 0, 1, 0}},
    };

    const auto printVector = [](const vector<int>& values) {
        cout << '[';
        for (size_t i = 0; i < values.size(); ++i) {
            if (i > 0) {
                cout << ", ";
            }
            cout << values[i];
        }
        cout << ']';
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [input, expected] = testCases[i];
        auto temperatures = input;
        const vector<int> actual = solution.dailyTemperatures(temperatures);
        const bool ok = actual == expected;
        passed += ok;

        cout << "用例 " << i + 1 << ": temperatures = ";
        printVector(input);
        cout << "，预期 = ";
        printVector(expected);
        cout << "，实际 = ";
        printVector(actual);
        cout << "，" << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
