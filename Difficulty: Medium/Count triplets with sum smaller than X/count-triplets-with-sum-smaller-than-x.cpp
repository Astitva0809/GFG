//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        sort(arr,arr+n);
        long long cnt=0;
        
        for(int i=0;i<n-2;i++){
            
            int l=i+1;
            int r=n-1;
            while(l<r){
              long long res=arr[i]+arr[l]+arr[r];
              if(res<sum){
                  cnt+=(r-l);
                  l++;
              }
              else r--;
            }
        }
        
 return cnt;  }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(n, sum, arr);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends