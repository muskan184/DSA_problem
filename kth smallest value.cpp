
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
      int n=arr.size();
      priority_queue<int>maxHeap;
      for(int i=0;i<n;i++){
          maxHeap.push(arr[i]);
          
          if(maxHeap.size()>k) maxHeap.pop();
      }
      
      return maxHeap.top();
        
    }
};
