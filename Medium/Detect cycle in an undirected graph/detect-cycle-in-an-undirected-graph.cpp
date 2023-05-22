//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
        bool bfs(int src,int V, vector<int> adj[],vector<int>&visited) {
            queue<pair<int, int>> q;
            q.push({src, -1});
            visited[src] = 1;
            while(!q.empty()){
                int curNode = q.front().first;
                int curNodeParent = q.front().second;
                q.pop();
                for(auto it : adj[curNode]){
                    if(!visited[it]){
                        visited[it]=true;
                        q.push({it,curNode});
                    }
                    else {
                        if(it!=curNodeParent){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        bool bfsSol(int V , vector<int> adj[]){
            vector<int> visited(V, 0);
            bool ans = false;
            for(int i=0;i<V;i++){
                if(!visited[i]){
                    ans = ans || bfs(i,V,adj,visited);
                }
            }
            return ans;
        }    
    public:
        // Function to detect cycle in an undirected graph.
        bool isCycle(int V, vector<int> adj[]) {
            // Code here
            return bfsSol(V, adj);}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends