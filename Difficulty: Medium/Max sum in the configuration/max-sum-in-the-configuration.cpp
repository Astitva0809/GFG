//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int arr[], int n) {
        // Your code here
           long long sum = 0;
    long long s0 = 0;

   
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        s0 += (long long)arr[i] * i; 
    }

    long long maxi = s0;
    long long si = s0;

    // Calculate maximum sum after each rotation
    for (int i = 0; i < n - 1; i++) {
        long long sip = si + sum - (long long)n * arr[n - i - 1]; 
        maxi = max(maxi, sip);
        si = sip;
    }

    return maxi;  }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends