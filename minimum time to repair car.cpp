class Solution {
public:
    bool minimumTime(vector<int>& nums ,int cars,long long mid){
        long long reparedCar=0;

        for(int r:nums){
            long long car=mid/r;
             long long c = floor(sqrt(car));
            reparedCar+=c;
        }
        return reparedCar >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1e14;
        while (l < r) {
            long long mid = (l + r) / 2;
            if (minimumTime(ranks, cars, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
