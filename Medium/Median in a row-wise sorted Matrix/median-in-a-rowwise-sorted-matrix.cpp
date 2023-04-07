//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int canBeMid(vector<vector<int>> &matrix, int R, int C, int val) {
    int cnt = 0;
    for (int i = 0; i < R; i++) {
        vector<int> &vec = matrix[i];
        cnt += (upper_bound(vec.begin(), vec.end(), val) - vec.begin());
    }
    return cnt <= ((R * C) / 2);
}

int median(vector<vector<int>> &matrix, int R, int C) {
    int lo = 1;
    int hi = 1e9;
    while (lo <= hi) {
        int mid = (hi + lo) / 2;
        if (canBeMid(matrix, R, C, mid)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return lo ;
}
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends