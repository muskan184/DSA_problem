class Solution {
public:
    string getCount(int n){
        string s = to_string(n);
        sort(s.begin(),s.end());
        return s;
    }

    bool reorderedPowerOf2(int n) {
        string target = getCount(n);
        for(int i=0;i<31;i++){
            if(target == getCount(1 << i)) return true;
        }
        return false;
    }
};
