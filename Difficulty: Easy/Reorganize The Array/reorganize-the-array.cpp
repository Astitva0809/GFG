//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrange(const vector<int>& nums) {
        // Code here
          std::unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        std::vector<int> arr(nums.size(), -1); // Initializing the array with -1
        for (size_t i = 0; i < nums.size(); i++) {
            if (mp.find(i) != mp.end()) { 
                arr[i] = i;  
            }
        }

        return arr;}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends