//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    int count=0;
    
    void dfs(int src,vector<int>adj[],vector<int>&vis){
        
        count++;
        vis[src]=1;
        
        for(auto it:adj[src]){
            
            if(vis[it]==0){
                
                dfs(it,adj,vis);
            }
        }
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int>vis(V,0);
	    int ans=-1;
	    
	    for(int i=0; i<V; i++){
	        
	        if(vis[i]==0){
	            
	            dfs(i,adj,vis);
	            
	            if(count==V){
	                
	                ans=i;
	                break;
	            }
	            
	            count=0;
	            for(int j=0; j<V; j++){
	                
	                vis[j]=0;
	            }
	        }
	    }
	    
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
