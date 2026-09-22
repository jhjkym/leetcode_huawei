#include <bits/stdc++.h>
using namespace std;

// 155. 最小栈
// st 保存数据，minst 同步保存每一层的最小值。
class MinStack {
    stack<int> st;
    stack<int> minst;

public:
    MinStack() {
        minst.push(INT_MAX);
    }

    void push(int val) {
        st.push(val);
        minst.push(min(val, minst.top()));
    }

    void pop() {
        st.pop();
        minst.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minst.top();
    }
};

int main() {
    vector<pair<int, int>> results;

    MinStack stack1;
    stack1.push(-2);
    stack1.push(0);
    stack1.push(-3);
    results.push_back({stack1.getMin(), -3});
    stack1.pop();
    results.push_back({stack1.top(), 0});
    results.push_back({stack1.getMin(), -2});

    MinStack stack2;
    stack2.push(2);
    stack2.push(2);
    stack2.push(1);
    results.push_back({stack2.getMin(), 1});
    stack2.pop();
    results.push_back({stack2.getMin(), 2});
    stack2.pop();
    results.push_back({stack2.top(), 2});

    MinStack stack3;
    stack3.push(INT_MAX);
    stack3.push(INT_MIN);
    results.push_back({stack3.getMin(), INT_MIN});
    stack3.pop();
    results.push_back({stack3.getMin(), INT_MAX});

    size_t passed = 0;
    for (size_t i = 0; i < results.size(); ++i) {
        bool ok = results[i].first == results[i].second;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << results[i].second
             << "，实际 = " << results[i].first << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << results.size() << '\n';
    return passed == results.size() ? 0 : 1;
}
