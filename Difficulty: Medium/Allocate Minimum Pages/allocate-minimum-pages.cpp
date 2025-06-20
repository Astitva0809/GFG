class Solution {
  public:
      bool ispossible(vector<int> &arr, int pages,int k){
      int cnt=1;
      int sum=0;
      for(int i=0;i<arr.size();i++){
         
         if(sum+arr[i]<=pages){
             
             sum+=arr[i];
         }
         else{
             cnt++;
             if(cnt>k || arr[i]>pages){
                 return false;
             }
             sum=arr[i];
             
             
         }
      }
     
          return true;
      
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        int left=*min_element(arr.begin(),arr.end());
        int right=accumulate(arr.begin(),arr.end(),0);
        if(k>arr.size()){
            return -1;
        }
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(ispossible(arr,mid,k)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
            
        }
        return ans;
    }
};