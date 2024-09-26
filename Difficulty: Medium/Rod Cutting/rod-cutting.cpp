//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int idx,int price[],int len,int n,vector<vector<int>>& dp)
{
   
    if(len==0) return 0;
    if(idx==n) return -1e9;

    if(dp[idx][len]!=-1) return dp[idx][len];

    int nottake=solve(idx+1,price,len,n,dp);
    int take=-1e9;
    if(len>=(idx+1))
    take=price[idx]+solve(idx,price,len-(idx+1),n,dp);

 
    return dp[idx][len]=max(take,nottake);
}
int cutRod(int price[], int n) {
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return solve(0,price,n,n,dp);

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends