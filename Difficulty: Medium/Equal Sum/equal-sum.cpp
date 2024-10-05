//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string equilibrium(vector<int> &arr) {
        // code here
            int right_sum = 0;
        for(int i = 0;i<arr.size();i++){
            right_sum = right_sum+arr[i];
        }
        int left_sum = 0;
        for(int i=0;i<arr.size();i++){
            if(left_sum == right_sum-arr[i]){
                
                return "true";
            }
            else{
                left_sum = left_sum+arr[i];
                right_sum = right_sum-arr[i];
            }
        }
        return "false";
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        string res = obj.equilibrium(arr);
        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends