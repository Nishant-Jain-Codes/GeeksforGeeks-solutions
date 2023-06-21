//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends





class Solution {
public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N,vector<long long int>(sum+1,-1));
        return memoisation(N-1,sum,coins,dp);
        return recursion(N-1,sum,coins);
    }
private:
    //time complexity greater than O(2^n)
    //space complexity  O(sum)
    long long int recursion(int idx , int sum , int * coins){
        if(idx<0){
            return sum==0;
        }
        long long int notTake = recursion(idx-1,sum,coins);
        long long int take = 0;
        if(sum-coins[idx]>=0){
            take = recursion(idx,sum-coins[idx],coins);
        }
        return notTake+take;
        
    }
    long long int memoisation(int idx , int sum , int * coins,vector<vector<long long int>>& dp){
        if(idx<0){
            return sum==0;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        long long int notTake = memoisation(idx-1,sum,coins,dp);
        long long int take = 0;
        if(sum-coins[idx]>=0){
            take = memoisation(idx,sum-coins[idx],coins,dp);
        }
        return dp[idx][sum] = notTake+take;
        
    }
};

















//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends