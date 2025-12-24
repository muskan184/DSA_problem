class Solution {
public:
int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    int totalApples = 0;
    for(int x : apple) totalApples += x;

    sort(capacity.begin(), capacity.end(), greater<int>());

    int curr = 0;
    int count = 0;

    for(int c : capacity){
        curr += c;
        count++;
        if(curr >= totalApples) return count;
    }

    return count;
}
};
