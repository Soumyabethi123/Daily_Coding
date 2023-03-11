//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void find(int i,int j,int n,int m,vector<vector<char>>& grid,vector<vector<int>>& vis){
        
        vis[i][j]=1;
        
        if(i<n && i>=0 && j-1<m && j-1>=0){
            
            if(vis[i][j-1]==0 && grid[i][j-1]=='1'){
                
                find(i,j-1,n,m,grid,vis);
            }
        }
        
        if(i<n && i>=0 && j+1<m && j+1>=0){
            
            if(vis[i][j+1]==0 && grid[i][j+1]=='1'){
                
                find(i,j+1,n,m,grid,vis);
            }
        }
        
        if(i+1<n && i+1>=0 && j<m && j>=0){
            
            if(vis[i+1][j]==0 && grid[i+1][j]=='1'){
                
                find(i+1,j,n,m,grid,vis);
            }
        }
        
         if(i+1<n && i+1>=0 && j+1<m && j+1>=0){
            
            if(vis[i+1][j+1]==0 && grid[i+1][j+1]=='1'){
                
                find(i+1,j+1,n,m,grid,vis);
            }
        }
        
         if(i+1<n && i+1>=0 && j-1<m && j-1>=0){
            
            if(vis[i+1][j-1]==0 && grid[i+1][j-1]=='1'){
                
                find(i+1,j-1,n,m,grid,vis);
            }
        }
        
        
        if(i-1<n && i-1>=0 && j<m && j>=0){
            
            if(vis[i-1][j]==0 && grid[i-1][j]=='1'){
                
                find(i-1,j,n,m,grid,vis);
            }
        }
        
         if(i-1<n && i-1>=0 && j+1<m && j+1>=0){
            
            if(vis[i-1][j+1]==0 && grid[i-1][j+1]=='1'){
                
                find(i-1,j+1,n,m,grid,vis);
            }
        }
        
         if(i-1<n && i-1>=0 && j-1<m && j-1>=0){
            
            if(vis[i-1][j-1]==0 && grid[i-1][j-1]=='1'){
                
                find(i-1,j-1,n,m,grid,vis);
            }
        }
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int ans=0;
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(grid[i][j]=='1'){
                    
                    if(vis[i][j]==0){
                        
                        ans++;
                        find(i,j,n,m,grid,vis);
                    }
                }
            }
        }
    
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
