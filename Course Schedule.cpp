class Solution {
public:

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adj(numCourses);
    for(auto& pre : prerequisites) {
        int course = pre[0];
        int prerequisite = pre[1];
        adj[prerequisite].push_back(course);
        indegree[course]++;
    }
    queue<int> q;
    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        count++;

        for(int neighbor : adj[current]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return count == numCourses; 
}

};
