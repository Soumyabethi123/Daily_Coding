class Solution {
public:

    //int ans=0;

    void dfs(int n,vector<int>& manager, vector<int>& inform,vector<int>&vis,vector<int> adj[]){

         vis[n]=1;

         //ans+=inform[n];

         for(auto it:adj[n]){

             if(vis[it]==0){

                 dfs(it,manager,inform,vis,adj);
             }
         }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& inform) {
        
        vector<int> adj[n];
        int head;

        for(int i=0;i<n; i++){

            if(manager[i]==-1){

                continue;
            }
            adj[manager[i]].push_back(i);
        }

        vector<int>vis(n,0);

        int ans=0;

        queue<pair<int,int>>q;
        q.push({headID,inform[headID]});

        vis[headID]=1;

        while(true){

            int s=q.size();

            if(s==0){
                break;
            }

            for(int i=0; i<s; i++){

                int front=q.front().first;
                int len=q.front().second;

                q.pop();

                if(adj[front].size()==0){

                    ans=max(ans,len);
                }

                for(auto it:adj[front]){

                   if(!vis[it]){

                      vis[it]=1;
                      q.push({it,len+inform[it]});
                   }
               }
            }
           
        }

        return ans;
    }
};
