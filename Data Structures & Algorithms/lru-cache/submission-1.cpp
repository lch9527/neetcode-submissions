class LRUCache {
private:
    int capacity;
    list<int> order;
    unordered_map<int, pair<int,list<int>::iterator>> cashe;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cashe.find(key) == cashe.end()){
            return -1;
        }
        order.erase(cashe[key].second);
        order.push_back(key);
        // move the key to the back;
        cashe[key].second = --order.end();
        //update the iteraror
        return cashe[key].first;
        
    }
    
    void put(int key, int value) {
        if(cashe.find(key)!=cashe.end()){
            // if we alreadly have the key
            order.erase(cashe[key].second);
        }
        else if(cashe.size()>=capacity){
            // if the cashe alreadlly full
            int lru = order.front();
            cashe.erase(lru);
            order.pop_front();
        }

        order.push_back(key);
        cashe[key] = {value,--order.end()};
    }
};
