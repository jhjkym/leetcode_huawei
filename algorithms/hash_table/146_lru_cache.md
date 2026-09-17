# 146. LRU 缓存

- 算法分类：哈希表、双向链表。
- 数据结构：`unordered_map` + `list`。
- 对应代码：[146_lru_cache.cpp](./146_lru_cache.cpp)。
- 掌握状态：**很难不会，需要大量背诵。**

## 背诵模板

哈希表保存 `key -> 链表节点迭代器`，用于 `O(1)` 找到缓存；双向链表维护使用顺序，头部是最近使用，尾部是最久未使用。

```cpp
class LRUCache {
    using Node = pair<int, int>;
    int capacity;
    list<Node> cache;
    unordered_map<int, list<Node>::iterator> table;

    void moveToFront(list<Node>::iterator it) {
        cache.splice(cache.begin(), cache, it);
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = table.find(key);
        if (it == table.end()) return -1;
        moveToFront(it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = table.find(key);
        if (it != table.end()) {
            it->second->second = value;
            moveToFront(it->second);
            return;
        }
        cache.push_front({key, value});
        table[key] = cache.begin();
        if (cache.size() > capacity) {
            int oldKey = cache.back().first;
            table.erase(oldKey);
            cache.pop_back();
        }
    }
};
```

**口诀：访问移到头，新增放到头；超容量删尾巴。**

## 操作过程

- `get(key)`：找不到返回 `-1`；找到后把节点移到头部并返回 value。
- `put(key,value)`：key 已存在则更新 value 并移到头部；key 不存在则在头部插入。超过容量时删除尾部节点，并从哈希表删除它的 key。

`list::splice` 可以在 `O(1)` 时间内移动链表节点，节点地址和迭代器保持有效，因此哈希表中的迭代器不需要更新。

## 易错点

- 哈希表存的是链表迭代器，不是 value；这样才能在 `O(1)` 时间定位并移动节点。
- `get` 也会改变最近使用顺序，不能只返回 value。
- 更新已有 key 时不能新增节点，否则会出现重复 key。
- 淘汰前先读取 `cache.back().first`，再从哈希表删除，最后 `pop_back()`。
- `cache.begin()` 是最近使用位置，`cache.end()` 不能解引用。
- 本题容量为正数；每次插入后最多保留 `capacity` 个节点。

## 复杂度

`get` 和 `put` 的平均时间复杂度都是 `O(1)`，空间复杂度为 `O(capacity)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/hash_table/146_lru_cache.cpp -o build/146
./build/146
```
