//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<int>key(V,INT_MAX);
        
        vector<bool>mst(V,false);
        
        vector<int>parent(V,-1);
        
        //randomly select any vertex
        int src=0;
        
        key[src]=0;
        
        while(true){
            
            //to find minimum from key
            int min_key=INT_MAX;
            int min_node=-1;
            int flag=0;
            
            for(int i=0; i<V; i++){
                
                if(mst[i]==false){
                    
                    flag=1;
                    
                    if(key[i] < min_key){
                        
                        min_key=key[i];
                        min_node=i;
                    }
                }
            }
            
            if(flag==0){
                
                break;
            }
            
            mst[min_node]=true;
            
            for(auto it:adj[min_node]){
                
                
                int node=it[0];
                int weight=it[1];
                
                if(!mst[node] && key[node] > weight){
                    
                    key[node]=weight;
                    
                    parent[node] = min_node;
                }
            
            }
        }
        
        int ans=0;
        
        for(int i=0; i<V; i++){
            
            //cout<<key[i]<<" ";
            ans=ans+key[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
