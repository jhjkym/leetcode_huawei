# 146. LRU 缓存

- 算法分类：哈希表、双向链表。
- 数据结构：`unordered_map` + `list`。
- 对应代码：[146_lru_cache.cpp](./146_lru_cache.cpp)。
- 掌握状态：最简背诵模板。

## 背诵答案

```cpp
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
```

## 背诵口诀

> 旧的先删除，新的放开头；
> 超容量删尾巴；`get` 调 `put` 刷新位置。

`cache` 中每个元素是 `{key, value}`：

- `front` 是最近使用；
- `back` 是最久未使用。

`position` 保存 `key -> list 迭代器`，用于 `O(1)` 找到并删除节点。

## 只记 `put`

存在旧节点就先删除，然后无论更新还是新增，都统一放到链表头部：

```cpp
if (position.count(key)) cache.erase(position[key]);
cache.push_front({key, value});
position[key] = cache.begin();
```

超过容量就删除尾部，同时删除哈希表记录：

```cpp
int oldKey = cache.back().first;
position.erase(oldKey);
cache.pop_back();
```

`get` 找到 value 后调用一次 `put(key, value)`，直接复用刷新逻辑。

## 易错点

- `get` 也算一次使用，必须刷新位置。
- 更新已有 key 时要先删除旧节点，避免出现重复 key。
- 头插后要更新 `position[key]`。
- 淘汰时必须同时删除哈希表和链表中的记录。

`get` 和 `put` 的平均时间复杂度都是 `O(1)`，空间复杂度为 `O(capacity)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/hash_table/146_lru_cache.cpp -o build/146
./build/146
```
