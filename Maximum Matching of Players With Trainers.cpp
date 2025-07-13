class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
         sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int i = 0; // pointer for players
    int j = 0; // pointer for trainers
    int matches = 0;

    while (i < players.size() && j < trainers.size()) {
        if (players[i] <= trainers[j]) {
            matches++;
            i++;
            j++;
        } else {
            j++; // move to a stronger trainer
        }
    }

    return matches;
    }
};
