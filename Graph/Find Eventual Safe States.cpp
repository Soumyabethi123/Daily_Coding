class Solution {
public:

    bool dfs(int src,vector<int> adj[],vector<int>&vis,vector<int>&vis2 , vector<int>&cycle){
        
        vis[src]=1;
        vis2[src]=1;
        
        for(auto it:adj[src]){
            
            if(vis[it]==1 && vis2[it]==1){
                
                cycle[src]=1;
                return true;
            }
            else if(vis[it]==0){

                bool temp=dfs(it,adj,vis,vis2,cycle);
                
                if(temp==true){
                    cycle[src]=1;
                    return true;
                }
            }
        }
        
        vis2[src]=0;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int>safe;

        int n=graph.size();

        vector<int> adj[n];

    
        for(int i=0; i<n; i++){

            for(int j=0; j<graph[i].size(); j++){

                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int>cycle(n,0);

        vector<int>vis(n,0);
        vector<int>vis2(n,0);
        
        for(int i=0; i<n; i++){

            if(vis[i]==0){

                dfs(i,adj,vis,vis2,cycle);
            }
        }

        for(int i=0; i<n; i++){

            if(cycle[i]==0){

                safe.push_back(i);
            }
        }

        return safe;
    }
};
