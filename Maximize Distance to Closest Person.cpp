class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int maxDist = 0;
        int lastPerson = -1;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (lastPerson == -1) {
                    maxDist = i;
                } else {
                    maxDist = max(maxDist, (i - lastPerson) / 2);
                }
                lastPerson = i;
            }
        }

        if (seats[n - 1] == 0) {
            maxDist = max(maxDist, n - 1 - lastPerson);
        }

        return maxDist;
    }
};
