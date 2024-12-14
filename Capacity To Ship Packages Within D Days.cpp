class Solution {
public:
    int findDay(vector<int> &arr,int mid){
        int days=1,load=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+load>mid){
                days+=1;
                load =arr[i];
            }else{
                load +=arr[i];
            }        
        }
        return days;
    }

    int shipWithinDays(vector<int>& arr, int days) {
     int low = *max_element(arr.begin(),arr.end());
     int high =accumulate(arr.begin(),arr.end(),0);

     while(low<= high){
        int mid=(low+high)/2;
        int day = findDay(arr,mid);
        if(day<=days){
            high=mid-1;
        }else{
            low=mid+1;
        }
     } 
     return low;  
    }
};
