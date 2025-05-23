//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    bool present( int ch, int pre[] ){
        return pre[ch] == 1;
    }
    void checkAndAdd( int ch, int pre[], int f[] ){
        if ( present(ch, pre) ) f[ch]++;
    }
    void checkAndSub( int ch, int pre[], int f[] ){
        if ( present(ch, pre) ) f[ch]--;
    }
    bool valid( int f[] ){
        for ( int i = 0; i<30; i++ ) if ( f[i] > 0 ) return false;
        return true;
    }
    public:
    string smallestWindow (string s, string p){
        int n = s.size(), j = 0, pre[30], f[30], res = INT_MAX; string finalS = "-1"; 
        for ( int i = 0; i<30; i++ ) pre[i] = 0, f[i] = 0;
        for ( auto i : p ) {
            pre[i-'a'] = 1; 
            f[i-'a']++;
        }
        for ( int i = 0; i<n; i++ ){
            while ( j < n && !valid(f) ){
                checkAndSub(s[j]-'a', pre, f);
                j++;
            }
            if ( res > j-i && valid(f) ){
                res = j-i;
                finalS = s.substr(i, j-i);
            }
            checkAndAdd(s[i]-'a', pre, f);
        } return finalS;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends