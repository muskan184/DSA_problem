class LRUCache {
public:
    int capacity;
    list<pair<int,int>>cache;

    unordered_map<int,list<pair<int,int>>::iterator>hash;
    LRUCache(int cap) {
        capacity=cap;
    }
    
    int get(int key) {
        if(hash.find(key)==hash.end()){
            return -1;
        }
        auto it= hash[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key,value});
        hash[key]=cache.begin();

        return value;
        
    }
    
    void put(int key, int value) {
        if(hash.find(key)!=hash.end()){
            cache.erase(hash[key]);
        }
        cache.push_front({key,value});
        hash[key]=cache.begin();

        if(cache.size() >capacity){
            auto last=cache.back();
            hash.erase(last.first);
            cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
