class LFUCache {
public:
int capacity,minfreq;
unordered_map<int,pair<int,int>>ktvfreq;
unordered_map<int,list<int>>freqtokeys;
unordered_map<int,list<int>::iterator>keytoiter;

    LFUCache(int capacity) {
        this->capacity=capacity;
        minfreq=0;
    }
    
    int get(int key) {
        if(ktvfreq.find(key)== ktvfreq.end())
        return -1;

        int val= ktvfreq[key].first;
        int freq=ktvfreq[key].second;

        freqtokeys[freq].erase(keytoiter[key]);

        if(freqtokeys[freq].empty()){
            freqtokeys.erase(freq);
            if(minfreq== freq) minfreq++;
        }  
            ktvfreq[key].second++;
            freqtokeys[freq+1].push_back(key);
            keytoiter[key]=--freqtokeys[freq+1].end();

            return val;
          }
    
    void put(int key, int value) {
        if(capacity==0) return ;

        if(ktvfreq.find(key) != ktvfreq.end()){
            ktvfreq[key].first=value;
            get(key);
            
            return;        }
        
        if(ktvfreq.size()>=capacity){
            int ifukey = freqtokeys[minfreq].front();
            freqtokeys[minfreq].pop_front();

            if(freqtokeys[minfreq].empty())

            freqtokeys.erase(minfreq);

            ktvfreq.erase(ifukey);
            keytoiter.erase(ifukey);

        }
        ktvfreq[key] ={value,1};
        freqtokeys[1].push_back(key);
        keytoiter[key]=--freqtokeys[1].end();
        minfreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
