//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
    const int mod = 1e9 + 7;
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
        vector<vector<int>> dp(n + 1,vector<int>(2, 0));
        dp[0][0] = 1;
        dp[0][1] = 1;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][1] = dp[i - 1][0];
        }

        return (dp[n-1][0] + dp[n-1][1]) % mod;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends