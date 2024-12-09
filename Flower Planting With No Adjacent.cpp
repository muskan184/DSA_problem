class Solution {
public:
bool valid(unordered_map<int,vector<int>> &g,int node,int rang,vector<int> &color){
        for(auto &child:g[node]){
            if(color[child]==rang) return 0;
        }
        return 1;
    }
    bool solve(unordered_map<int,vector<int>> &g,int node,int n,vector<int> &color){
        if(node==n+1) return 1;
        for(int i=1;i<=4;i++){
            if(valid(g,node,i,color)){
                color[node]=i;
                if(solve(g,node+1,n,color)) return 1;
                color[node]=0;
            }
        }
        return 0;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& A) {
        unordered_map<int,vector<int>> g;
        for(auto &p:A){
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        vector<int> color(n+1,0);
        solve(g,1,n,color);
        color.erase(begin(color),begin(color)+1);
        return color;
    }
};
