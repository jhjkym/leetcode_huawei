# 207. 课程表

- 算法分类：拓扑排序、BFS。
- 数据结构：邻接表、入度数组、队列。
- 对应代码：[207_course_schedule.cpp](./207_course_schedule.cpp)。
- 掌握状态：Kahn 拓扑排序模板。

## 背诵答案

```cpp
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
```

## 背诵口诀

> 先建图、算入度；
> 零入度先入队；
> 出队一门，后续入度减一；
> 最后看是否学完全部。

先修关系 `[course, prerequisite]` 表示：

```text
prerequisite -> course
```

因此从先修课程指向后续课程，并增加后续课程的入度。入度为 `0` 表示这门课程没有尚未完成的先修课程，可以立即学习。

每学完一门课程，就删除它发出的所有边，也就是让后续课程的入度减一。新的入度为 `0` 时，将该课程加入队列。

## 为什么能判断环

如果图中存在环，环内每门课程都依赖环内另一门课程，它们的入度永远无法降为 `0`，因此最终完成课程数会小于总课程数。

```cpp
return finished == numCourses;
```

## 易错点

- `[a, b]` 表示学 `a` 前必须学 `b`，建边方向是 `b -> a`。
- 增加的是后续课程 `a` 的入度。
- 所有初始入度为 `0` 的课程都要入队，包括没有出现在先修关系中的课程。
- 入度减到 `0` 时才能入队，并且只入队一次。

设课程数为 `V`、先修关系数为 `E`，时间复杂度为 `O(V+E)`，空间复杂度为 `O(V+E)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/graph_traversal/207_course_schedule.cpp -o build/207
./build/207
```
