class LRUCache {
private:
    int capacity;
    list<int> order;
    unordered_map<int, pair<int, list<int>::iterator>> cashe;
    // key -> {value, iterator to key in order}

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cashe.find(key) == cashe.end()) {
            return -1;
        }

        int value = cashe[key].first;

        order.erase(cashe[key].second);
        order.push_back(key);

        cashe[key] = {value, prev(order.end())};

        return value;
    }
        
    void put(int key, int value) {
        if (cashe.find(key) != cashe.end()) {
            order.erase(cashe[key].second);
        }
        else if (cashe.size() >= capacity) {
            int lru = order.front();
            cashe.erase(lru);
            order.pop_front();
        }

        order.push_back(key);
        cashe[key] = {value, prev(order.end())};
    }
};