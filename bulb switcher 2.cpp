class Solution {
public:
    int flipLights(int n, int k) {
        if(k == 0) return 1;
        if(n == 1) return 2;
        if(n == 2 && k == 1) return 3;
        if(n == 2 || k == 1) return 4;
        if(k == 2) return 7;
        return 8;
    }
};
