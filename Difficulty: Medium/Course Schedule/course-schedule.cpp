//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
 vector<int> topo(unordered_map<int, vector<int>>& adjl, vector<int> indegree, int n) {
        queue<int> q;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            for (auto it : adjl[curr]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        // If result has all nodes, return it, else return empty vector (cycle detected)
        if (result.size() == n)
            return result;
        return {};
    }

    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        unordered_map<int, vector<int>> adjl;
        vector<int> indegree(n, 0);

        for (auto it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adjl[b].push_back(a);
            indegree[a]++;
        }

        return topo(adjl, indegree, n); 
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<int> adj[]) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u, v});
        }

        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);

        Solution obj;
        vector<int> res = obj.findOrder(n, prerequisites);

        if (check(n, res, adj))
            cout << "true" << endl;

        else
            cout << "false\n";
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends