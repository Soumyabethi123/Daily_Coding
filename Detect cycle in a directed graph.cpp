//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int src,vector<int> adj[],vector<int>&vis,vector<int>&vis2){
        
        vis[src]=1;
        vis2[src]=1;
        
        for(auto it:adj[src]){
            
            if(vis[it]==1 && vis2[it]==1){
                
                return true;
            }
            else if(vis[it]==0){
                
                bool temp=dfs(it,adj,vis,vis2);
                
                if(temp==true){
                    return true;
                }
            }
        }
        
        vis2[src]=0;
        
        return false;
    }
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int>vis(V,0);
        vector<int>vis2(V,0);
        
        for(int i=0; i<V; i++){
            
            if(vis[i]==0){
                
                bool temp=dfs(i,adj,vis,vis2);
                
                if(temp==true){
                    
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
