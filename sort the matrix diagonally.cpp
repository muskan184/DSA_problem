class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int>v;
        int i,j,id;
        for(int k=0;k<mat.size();k++){
            i=k,j=0;
            v.clear();
            while(i<mat.size() && j<mat[0].size()) v.push_back(mat[i][j]),i++,j++;
            sort(v.begin(),v.end());
            i=k,j=0,id=0;
            while(i<mat.size() && j<mat[0].size()) mat[i][j]=v[id++],i++,j++;
        }
        for(int k=0;k<mat[0].size();k++){
            i=0,j=k;
            v.clear();
            while(i<mat.size() && j<mat[0].size()) v.push_back(mat[i][j]),i++,j++;
            sort(v.begin(),v.end());
            i=0,j=k,id=0;
            while(i<mat.size() && j<mat[0].size()) mat[i][j]=v[id++],i++,j++;
        }
        return mat;
    }
};
