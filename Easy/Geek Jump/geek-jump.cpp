//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    int recursive(vector<int>& height , int start , int final){
        if(start >= final )
            return 0;
        int left = abs(height[start] - height[start +1]) + recursive(height, start+1, final);
        int right = abs(height[start] - height[start + 2]) + recursive(height, start+2, final);
        return min(left, right);
    }
    int memoisation(vector<int>& height, int start , int final,vector<int>& dp){
        if(start >= final )
            return 0;
        if(dp[start] != -1)
            return dp[start];
        
        int left = dp[start+1] != -1? dp[start+1]:abs(height[start] - height[start +1]) + recursive(height, start+1, final);
        int right = dp[start+2] != -1? dp[start+2]:abs(height[start] - height[start + 2]) + recursive(height, start+2, final);
        return dp[start] = min(left, right);
    }
    int tabulation(vector<int>& height , int n){
        vector<int> dp(n,-1);
        dp[0] = 0;
        dp[1] = abs(height[0] - height[1]);
        for(int i=2;i<n;i++){
            dp[i] = min(dp[i-1] + abs(height[i-1] - height[i]), dp[i-2] + abs(height[i-2] - height[i]));
        }
        return dp[n-1];        
    }
public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        return tabulation(height, n);
        vector<int> dp(n, -1);
        return memoisation(height,0,n-1,dp);
        return recursive(height, 0,n-1);
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends