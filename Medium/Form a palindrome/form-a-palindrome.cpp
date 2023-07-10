//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    int countMin(string str)
    {
        // complete the function here
        vector<vector<int>> dp(str.length(), vector<int>(str.length(), -1));
        return memoisation(str, 0, str.length() - 1, dp);
        return recursive(str , 0 , str.length()-1);
    }
private: 
    //time complexity : O(n^2)
    int recursive(string & str, int start , int end){
        if(start == end) return 0;
        if(start > end) return INT_MAX;
        if(str[start] == str[end]) 
            return recursive(str , start+1 , end-1);
        int leftTake = recursive(str, start+1 , end);
        int rightTake = recursive(str, start , end-1);
        return min(leftTake , rightTake) + 1;
    }
    int memoisation(string & str, int start , int end,vector<vector<int>> & dp){
        if(start == end) return 0;
        if(start > end) return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        if(str[start] == str[end]) 
            return memoisation(str , start+1 , end-1,dp);
        int leftTake = memoisation(str, start+1 , end,dp);
        int rightTake = memoisation(str, start , end-1,dp);
        return dp[start][end] = min(leftTake , rightTake) + 1;
    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends