class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

        priority_queue<int , vector<int> ,greater<int>> availableRooms;
        for(int i=0;i<n;i++) availableRooms.push(i);

          priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> ongoing;

        vector<int> roomCount(n,0);

        for(auto &m : meetings) {
            long long start = m[0] , end = m[1];

            while (!ongoing.empty() && ongoing.top().first <= start) {
            availableRooms.push(ongoing.top().second);
            ongoing.pop();
        }
        
        if (availableRooms.empty()) {
            
            auto earliest = ongoing.top();
            ongoing.pop();
            long long newStart = earliest.first;
            long long duration = end - start;
            long long newEnd = newStart + duration;
            ongoing.push({newEnd, earliest.second});
            roomCount[earliest.second]++;
        } else {
             int room = availableRooms.top();
            availableRooms.pop();
            ongoing.push({end, room});
            roomCount[room]++;
        }
    }
    
    int maxMeetings = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (roomCount[i] > maxMeetings) {
            maxMeetings = roomCount[i];
            ans = i;
        }
    }
    return ans;
 
    }
};
