class Solution {
public:
int pos(vector<int> &arr , int day,int m, int k){
    int cnt =0;
    int noOfBo =0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day){
        cnt++;
    }else{
        noOfBo +=(cnt/k);
        cnt=0;
    }
    }
    noOfBo +=(cnt/k);
    return noOfBo >=m;
}
    int minDays(vector<int>& arr, int r, int b) {
     long long val=r*1LL*b*1LL;
     if(val> arr.size()) return -1;
     int mini= INT_MAX ,maxi=INT_MIN;
     for(int i=0;i<arr.size();i++){
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
     }   
     int low=mini ,high=maxi;
     while(low<=high){
        int mid=(low+high)/2;
        if(pos(arr,mid,r,b)){
            high=mid-1;
        }
        else low =mid+1;
     }
     return low;
    }
};
