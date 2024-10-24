//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int> arr) {
        // Your code here
        int n=arr.size();
        map<int,int>mp;
        mp[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
           
            if(mp.find(sum)!=mp.end()){
                return true;
            }
             mp[sum]=1;
        }
   return false; }
};

//{ Driver Code Starts.

// Driver code
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        if (obj.subArrayExists(arr))
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends