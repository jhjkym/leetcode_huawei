#include <bits/stdc++.h>
using namespace std;

// 207. 课程表
// Kahn 拓扑排序：不断学习入度为 0 的课程。
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (const vector<int>& edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];
            graph[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> courses;
        for (int course = 0; course < numCourses; ++course) {
            if (indegree[course] == 0) courses.push(course);
        }

        int finished = 0;
        while (!courses.empty()) {
            int course = courses.front();
            courses.pop();
            finished++;

            for (int next : graph[course]) {
                indegree[next]--;
                if (indegree[next] == 0) courses.push(next);
            }
        }
        return finished == numCourses;
    }
};

int main() {
    struct TestCase {
        int numCourses;
        vector<vector<int>> prerequisites;
        bool expected;
    };

    const vector<TestCase> testCases = {
        {2, {{1, 0}}, true},
        {2, {{1, 0}, {0, 1}}, false},
        {1, {}, true},
        {1, {{0, 0}}, false},
        {4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, true},
        {5, {{1, 0}, {2, 1}, {3, 2}, {1, 3}}, false},
        {6, {{1, 0}, {2, 1}, {4, 3}}, true},
        {3, {{1, 0}, {2, 1}, {2, 0}}, true},
    };

    Solution solution;
    size_t passed = 0;
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<vector<int>> prerequisites = testCases[i].prerequisites;
        bool actual = solution.canFinish(testCases[i].numCourses, prerequisites);
        bool ok = actual == testCases[i].expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << boolalpha
             << testCases[i].expected << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << testCases.size() << '\n';
    return passed == testCases.size() ? 0 : 1;
}
