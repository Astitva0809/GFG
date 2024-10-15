//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int N, int tar)
    {
        // code here
        unordered_map<int,int>mp;
        mp[0]=1;
        int cnt=0;
        int ans=0;
        for(int i=0;i<N;i++){
         ans+=arr[i];
         if(mp.count(ans-tar))cnt+=mp[ans-tar];
         
         mp[ans]++;
        }
   return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends