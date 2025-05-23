//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

void dfs(int u,vector<int>adjl[],int vis[]){
    vis[u]=1;
    for(auto it :adjl[u]){
        if(vis[it]==0)dfs(it,adjl,vis);
    }

}

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
      vector<int>adjl[V];
      for(int i=0;i<V;i++){
          for(int j=0;j<V;j++){
              if(adj[i][j]==1 && i!=j){
                  adjl[i].push_back(j);
                  adjl[j].push_back(i);
              }
          }
      }
      int vis[V]={0};
      int cnt=0;
      for(int i=0;i<V;i++){
          if(vis[i]==0){
              cnt++;
              dfs(i,adjl,vis);
          }
      }
 return cnt;   }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends