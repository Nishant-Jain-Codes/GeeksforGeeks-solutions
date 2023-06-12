//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
private: 
    int recursive(int * arr , int n ){
        if(n<=0)
            return 0;
        return max(recursive(arr,n-1),arr[n]+recursive(arr,n-2));
    }
    int memoisation(int*arr , int n , vector<int>& dp ){
        if(n<=0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = max(recursive(arr,n-1),arr[n]+recursive(arr,n-2));
    }
    int tabulation(int *arr ,int n){
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = arr[0];
        for(int i = 2 ; i <= n ; i++){
            dp[i] = max(dp[i-1],arr[i-1]+dp[i-2]);
        }
        return dp[n];
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
        return tabulation(arr,n);
        vector<int> dp(n+1,-1);
        return memoisation(arr,n-1,dp);
        return recursive(arr,n-1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends