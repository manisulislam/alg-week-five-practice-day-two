//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    int parent[100000+5];
    int parentSize[100000+5];
    
    void dsu_set(int n){
        for(int i=0; i<n; i++){
            parent[i]=-1;
            parentSize[i]=1;
        }
    }
    
    int dsu_find(int node){
        while(parent[node]!=-1){
            node=parent[node];
        }
        return node;
    }
    
    void dsu_union(int a, int b){
        int leaderA= dsu_find(a);
        int leaderB= dsu_find(b);
        
        if(leaderA != leaderB){
            if(parentSize[leaderA] > parentSize[leaderB]){
                parent[leaderB]= leaderA;
                parentSize[leaderA]+=parentSize[leaderB];
            }
            else{
                parent[leaderA]= leaderB;
                parentSize[leaderB]+= parentSize[leaderA];
                
            }
            
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        dsu_set(V);
        for(auto val: adj[V]){
            int a= val.first;
            int b= val.second;
            int leaderA= dsu_find(a);
            int leaderB= dsu_find(b);
            
            if(leaderA == leaderB){
                return 1;
            }
            else{
                dsu_union(a,b);
                return 0;
            }
        }
    }
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