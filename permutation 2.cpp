class Solution {
public:
    void findAll( vector<int>& combination, vector<int>& nums, vector<bool>& visited, vector<vector<int>>& combinations )
    {
        if( combination.size() == nums.size())
        {
            combinations.push_back(combination);
            return;
        }
        for( int i = 0; i < nums.size(); ++i)
        {
            if(visited[i])
            {
                continue;
            }
            if( i > 0 && nums[i] == nums[i-1] && !visited[i-1])
                continue;

            combination.push_back(nums[i]);
            visited[i] = true;
            findAll(combination, nums, visited, combinations);
            combination.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end()); // sort is for handling the duplicates.
        vector<vector<int>> combinations;
        vector<int> combination;
        vector<bool> visited(nums.size(), false);
        findAll(combination, nums, visited, combinations);
        return combinations;    
    }
};
