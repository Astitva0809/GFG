//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
  int len = str.length();
    

    int last_digit = str[len - 1] - '0';
    
    if (last_digit >5) {
   
        str[len - 1] = '0';
        for (int i = len - 2; i >= 0; --i) {
            if (str[i] != '9') {
                str[i] = str[i] + 1;  
                break;
            } else {
                str[i] = '0'; 
            }
        }
    } else {
  
        str[len - 1] = '0';
    }
    
 
    return str;}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends