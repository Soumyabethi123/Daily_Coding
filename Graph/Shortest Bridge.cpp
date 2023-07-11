class Solution {
public:

    vector<pair<int,int>>first;
    vector<pair<int,int>>sec;

    vector<int>row = {1,-1,0,0};
    vector<int>col = {0,0,1,-1};

    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<int>>& grid,int n,int flag){

         vis[r][c]=1;
         if(flag==1){

             first.push_back({r,c});
         }
         else{
             sec.push_back({r,c});
         }

         for(int i=0; i<4; i++){

             int a=r+row[i];
             int b=c+col[i];

             if(a<n && b<n && a>=0 && b>=0 && vis[a][b]==0 && grid[a][b]==1){

                 dfs(a,b,vis,grid,n,flag);
             }
         }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        
        int n=grid.size();

        vector<vector<int>>vis(n,vector<int>(n,0));

        int flag=0;

        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){

                if(vis[i][j]==0 && grid[i][j]==1){

                    flag++;
                    dfs(i,j,vis,grid,n,flag);
                }
            }
        }

        int ans=INT_MAX;

        for(int i=0; i<first.size(); i++){

            for(int j=0; j<sec.size(); j++){

                ans= min(ans , ( abs(first[i].first - sec[j].first ) + abs(first[i].second - sec[j].second ) ) -1  );
            }
        }

        return ans;
    }
};
