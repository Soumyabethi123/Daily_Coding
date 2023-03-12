//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void bfs(int x,int y,vector<vector<int>> &grid,int n,int m){
        
        if(x<n && x>=0 && y<m && y>=0 && grid[x][y]==1){
            
            grid[x][y]=2;
            
            bfs(x-1,y,grid,n,m);
            bfs(x+1,y,grid,n,m);
            bfs(x,y-1,grid,n,m);
            bfs(x,y+1,grid,n,m);
            
        }
        else{
            
            return;
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n=grid.size();
        int m=grid[0].size();
    
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    
                    if(grid[i][j]==1){
                        
                        bfs(i,j,grid,n,m);
                    }
                }
            }
        }
        
        int ans=0;
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(grid[i][j]==1){
                    
                    ans++;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
