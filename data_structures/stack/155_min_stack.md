# 155. 最小栈

- 算法分类：栈、辅助状态。
- 数据结构：数据栈、最小值栈。
- 对应代码：[155_min_stack.cpp](./155_min_stack.cpp)。
- 掌握状态：带最小值的栈模板。

## 背诵答案

```cpp
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
```

## 背诵口诀

> 数据栈正常存值；
> 最小栈同步存入当前最小值；
> 压栈一起压，弹栈一起弹。

`minst` 先放入 `INT_MAX` 作为哨兵。压入 `val` 时，新最小值为：

```cpp
min(val, minst.top())
```

因此 `minst.top()` 始终是当前数据栈的最小值。弹出时两个栈同步弹出，上一层保存的最小值会自然恢复。

## 易错点

- 构造函数中先向 `minst` 压入 `INT_MAX`，这样第一次 `push` 不需要单独判断空栈。
- 每次 `push` 两个栈都要压入，每次 `pop` 两个栈都要弹出。
- 最小值重复时也必须再次压入最小栈。
- `top()` 返回 `st.top()`，`getMin()` 返回 `minst.top()`。
- 题目保证调用 `pop`、`top` 和 `getMin` 时栈非空。

`push`、`pop`、`top` 和 `getMin` 的时间复杂度都是 `O(1)`；两个栈的空间复杂度为 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 data_structures/stack/155_min_stack.cpp -o build/155
./build/155
```
