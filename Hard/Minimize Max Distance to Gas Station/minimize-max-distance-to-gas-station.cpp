//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     bool isPossible(vector<int> &stations, int K, double cap) {
        int allocated = 0;
        for (int i = 1; i < stations.size(); i++) {
            double distance = stations[i] - stations[i - 1];
            int newAllocated = floor(distance / cap);
            allocated += newAllocated;
        }
        return allocated <= K;
    }
    
    double findSmallestMaxDist(vector<int> &stations, int K) {
        double lo = 0.0, hi = 1e9;  // Adjusted initial values for lo and hi
        double epsilon = 1e-6;  // Adjusted epsilon value
        double answer = -1.0;
        
        while (hi - lo >= epsilon) {  // Adjusted the condition
            double mid = (hi + lo) / 2.0;
            if (isPossible(stations, K, mid)) {
                answer = mid;
                hi = mid - epsilon;
            } else {
                lo = mid + epsilon;
            }
        }
        
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends