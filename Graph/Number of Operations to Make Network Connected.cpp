class Solution {
public:

    void dfs(int src, vector<int>&vis ,vector<int> adj[] ){

        vis[src]=1;
        for(auto it:adj[src]){

            if(vis[it]==0){

                dfs(it,vis,adj);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& conn) {
        
        int edges=conn.size();

        if(edges >= n-1){

            vector<int> adj[n];

            for(int i=0; i<edges; i++){

                adj[conn[i][0]].push_back(conn[i][1]);
                adj[conn[i][1]].push_back(conn[i][0]);
            }

            int ans=0;

            vector<int>vis(n,0);

            for(int i=0; i<n; i++){

                 if(vis[i]==0){

                     ans++;
                     dfs(i,vis,adj);
                 }
            }

            return ans-1;
        }
        else{
            return -1;
        }
    }
};
