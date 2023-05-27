//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> Freq(n, 0); 
        vector<long long> minDist(n, -1); 
        vector<pair<int, int>> adj[n];

        
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];
            adj[u].emplace_back(v, d);
            adj[v].emplace_back(u, d);
        }

        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        int start = 0;
        int end = n - 1;

        
        if (start == end)
            return 1;

        pq.push({ 0, start }); 
        minDist[start] = 0;
        Freq[start] = 1;

        while (!pq.empty()) {
            long long curDist = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();

            if (curNode == end) {
                Freq[curNode] %= 1000000007;
                continue;
            }

            for (auto& it : adj[curNode]) {
                int nextNode = it.first;
                long long nextDist = curDist + it.second;

                
                if (minDist[nextNode] == -1 || minDist[nextNode] > nextDist) {
                    minDist[nextNode] = nextDist;
                    Freq[nextNode] = Freq[curNode];
                    pq.push({ nextDist, nextNode });
                }
                
                else if (minDist[nextNode] == nextDist) {
                    Freq[nextNode] += Freq[curNode];
                    Freq[nextNode] %= 1000000007;
                }
            }
        }

        return Freq[end];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends