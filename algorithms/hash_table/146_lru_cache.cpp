#include <bits/stdc++.h>
using namespace std;

// 146. LRU 缓存
// 哈希表负责 O(1) 找到节点，list 维护最近使用顺序。
// 口诀：旧的先删除，新的放开头；超容量删尾巴。

class LRUCache {
    size_t capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> position;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (position.count(key) == 0) return -1;
        int value = position[key]->second;
        put(key, value);
        return value;
    }

    void put(int key, int value) {
        if (position.count(key)) cache.erase(position[key]);

        cache.push_front({key, value});
        position[key] = cache.begin();
        if (cache.size() > capacity) {
            int oldKey = cache.back().first;
            position.erase(oldKey);
            cache.pop_back();
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct Operation { char type; int key; int value; };
    struct TestCase { int capacity; vector<Operation> operations; vector<int> expected; };
    const vector<TestCase> testCases = {
        {2, {{'p',1,1},{'p',2,2},{'g',1,0},{'p',3,3},{'g',2,0},{'p',4,4},{'g',1,0},{'g',3,0},{'g',4,0}}, {1,-1,-1,3,4}},
        {1, {{'p',1,10},{'g',1,0},{'p',2,20},{'g',1,0},{'g',2,0}}, {10,-1,20}},
        {2, {{'g',1,0},{'p',1,1},{'p',1,2},{'g',1,0}}, {-1,2}},
        {2, {{'p',1,1},{'p',2,2},{'g',1,0},{'p',3,3},{'g',2,0},{'g',1,0}}, {1,-1,1}},
        {3, {{'p',1,1},{'p',2,2},{'p',3,3},{'g',2,0},{'p',4,4},{'g',1,0},{'g',3,0},{'g',4,0}}, {2,-1,3,4}},
        {2, {{'p',0,0},{'p',-1,7},{'g',0,0},{'p',2,9},{'g',-1,0},{'g',0,0}}, {0,-1,0}},
        {2, {{'p',1,1},{'p',2,2},{'g',1,0},{'g',2,0},{'p',3,3},{'g',1,0},{'g',2,0},{'g',3,0}}, {1,2,-1,2,3}},
        {1, {{'p',5,5},{'p',5,6},{'g',5,0},{'p',6,7},{'g',5,0},{'g',6,0}}, {6,-1,7}},
    };

    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        LRUCache cache(testCase.capacity);
        vector<int> actual;
        for (const auto& op : testCase.operations) {
            if (op.type == 'p') cache.put(op.key, op.value);
            else actual.push_back(cache.get(op.key));
        }
        bool ok = actual == testCase.expected;
        passed += ok;
        cout << "用例 " << i + 1 << ": 预期 = [";
        for (size_t j = 0; j < testCase.expected.size(); ++j) {
            if (j > 0) cout << ", ";
            cout << testCase.expected[j];
        }
        cout << "]，实际 = [";
        for (size_t j = 0; j < actual.size(); ++j) {
            if (j > 0) cout << ", ";
            cout << actual[j];
        }
        cout << "]，" << (ok ? "PASS" : "FAIL") << '\n';
    }
    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
