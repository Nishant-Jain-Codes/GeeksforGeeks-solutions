//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

class Solution{
private: 
    //time complexity : O(2^n)
    //space complexity : O(n)
    int recursive(int * arr , int n ){
        if(n<=0)
            return 0;
        return max(recursive(arr,n-1),arr[n]+recursive(arr,n-2));
    }
    //time complexity : O(n)
    //space complexity : O(n)+O(n)
    int memoisation(int*arr , int n , vector<int>& dp ){
        if(n<=0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = max(recursive(arr,n-1),arr[n]+recursive(arr,n-2));
    }
    //time complexity : O(n)
    //space complexity : O(n)
    int tabulation(int *arr ,int n){
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = arr[0];
        for(int i = 2 ; i <= n ; i++){
            dp[i] = max(dp[i-1],arr[i-1]+dp[i-2]);
        }
        return dp[n];
    }
    //time complexity : O(n)
    //space complexity : O(1)
    int optimised(int *arr ,int n){
        if(n==0)
            return 0;
        vector<int> dp(n+1,-1);
        int prev2 = 0;
        int prev1 = arr[0];
        for(int i = 2 ; i <= n ; i++){
            int curr = max(prev1,arr[i-1]+prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:	
	// calculate the maximum sum with out adjacent
	int FindMaxSum(int *arr, int n) {
	    // code here
        return optimised(arr,n);
        return tabulation(arr,n);
        vector<int> dp(n+1,-1);
        return memoisation(arr,n-1,dp);
        return recursive(arr,n-1);
	}
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends