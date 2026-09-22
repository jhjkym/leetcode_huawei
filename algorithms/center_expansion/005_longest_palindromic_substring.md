# 5. 最长回文子串

## 最优背诵代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 1;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            expand(s, i, i, start, maxLength);
            expand(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }

private:
    void expand(const string& s, int left, int right,
                int& start, int& maxLength) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }

        int length = right - left - 1;
        if (length > maxLength) {
            start = left + 1;
            maxLength = length;
        }
    }
};
```

## 思路

每个回文串都有一个中心，从中心同时向左右扩展即可找到它。

每个位置需要扩展两次：

- `expand(s, i, i, ...)`：寻找奇数长度回文，例如 `aba`。
- `expand(s, i, i + 1, ...)`：寻找偶数长度回文，例如 `abba`。

扩展停止时，`left` 和 `right` 都已经越过有效回文，所以：

```cpp
int length = right - left - 1;
int start = left + 1;
```

## 为什么辅助函数可以写在后面

类中的所有成员函数在整个类定义中都可见。因此，`longestPalindrome` 可以调用后面定义的 `expand`，不需要提前声明。

`expand` 只为类内部服务，所以放在 `private` 中。

## 背诵口诀

> 每个位置扩两次，一次单中心，一次双中心；退出多走了一步，长度右减左减一，起点左加一。

## 复杂度

- 时间复杂度：`O(n²)`
- 辅助空间复杂度：`O(1)`，不计算返回结果所占空间
