struct CacheEntry {
    int key;
    int value;
    CacheEntry(int k, int v) : key(k), value(v) {}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        if (table.find(key) == table.end()) {
            return -1;
        }
        MoveToHead(key);
        return table[key]->value;
    }

    void set(int key, int value) {
        if (table.find(key) == table.end()) {
            CacheEntry newItem(key, value);
            if (cache.size() >= _capacity) {
                table.erase(cache.back().key);
                cache.pop_back();
            }
            cache.push_front(newItem);
            table[key] = cache.begin();
        } else {
            table[key]->value = value;
            MoveToHead(key);
        }
    }

  private:
    int _capacity;
    list<CacheEntry> cache;
    unordered_map<int, list<CacheEntry>::iterator> table;

    void MoveToHead(int key) {
        auto temp = *table[key];
        cache.erase(table[key]);
        cache.push_front(temp);
        table[key] = cache.begin();
    }

};

