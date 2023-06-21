//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
public:
    int findTargetSumWays(vector<int>&nums ,int target) {
        //Your code here
        unordered_map<int,unordered_map<int,int>> dp;
        return memoisation(nums.size()-1, nums, target, dp);
        return recursion(nums.size()-1, nums, target);
    }
private:
    int recursion(int idx , const vector<int> & nums , int target){
        if(idx < 0)
            return target == 0;
        int negative = recursion(idx-1,nums,target+nums[idx]);
        int positive =  recursion(idx-1,nums,target-nums[idx]);
        return positive + negative;
    }
    int memoisation(int idx , const vector<int> & nums , int target,unordered_map<int,unordered_map<int,int>> & dp){
        if(idx < 0)
            return target == 0;
        if(dp[idx].find(target) != dp[idx].end())
            return dp[idx][target];
        int negative = memoisation(idx-1,nums,target+nums[idx],dp);
        int positive =  memoisation(idx-1,nums,target-nums[idx],dp);
        return dp[idx][target] =  positive + negative;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends