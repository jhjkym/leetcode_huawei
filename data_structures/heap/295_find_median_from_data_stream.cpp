#include <bits/stdc++.h>
using namespace std;

// 295. 数据流的中位数
// 大顶堆保存较小的一半，小顶堆保存较大的一半。
class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() = default;

    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) return left.top();

        long long sum = left.top();
        sum += right.top();
        return sum / 2.0;
    }
};

int main() {
    vector<pair<double, double>> results;

    MedianFinder finder1;
    finder1.addNum(1);
    finder1.addNum(2);
    results.push_back({finder1.findMedian(), 1.5});
    finder1.addNum(3);
    results.push_back({finder1.findMedian(), 2.0});

    MedianFinder finder2;
    finder2.addNum(5);
    results.push_back({finder2.findMedian(), 5.0});
    finder2.addNum(-1);
    results.push_back({finder2.findMedian(), 2.0});
    finder2.addNum(10);
    results.push_back({finder2.findMedian(), 5.0});
    finder2.addNum(0);
    results.push_back({finder2.findMedian(), 2.5});

    MedianFinder finder3;
    finder3.addNum(INT_MAX);
    finder3.addNum(INT_MAX);
    results.push_back({finder3.findMedian(), INT_MAX});
    finder3.addNum(INT_MIN);
    results.push_back({finder3.findMedian(), INT_MAX});

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
