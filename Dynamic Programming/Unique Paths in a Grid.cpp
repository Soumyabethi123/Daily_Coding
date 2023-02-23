//User function Template for C++

class Solution {
  public:
  
    long int mod=1000000007;
    
    long int rec(int x,int y,vector<vector<int>> &grid,int n,int m,vector<vector<long int>> &dp){
        
        if(x<0 || y<0 || x>=n || y>=m){
            
            return 0;
        }
        else if(x==0 && y==0){
            
            return 1;
        }
        else if(grid[x][y]==0){
            
            return 0;
        }
        else if(dp[x][y] != -1){
            
            return dp[x][y]%mod;
        }
        else{
            
            long int up=rec(x-1,y,grid,n,m,dp);
            long int left=rec(x,y-1,grid,n,m,dp);
            
            dp[x][y]=(up%mod)+(left%mod);
            
            return dp[x][y]%mod;
        }
        
    }
    
    
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        
       vector<vector<long int>> dp( n , vector<long int> (m,-1)); 
        
        if(grid[0][0]==0 || grid[n-1][m-1]==0){
            
            return 0;
        }
        else{
            
            return rec(n-1,m-1,grid,n,m,dp);
        }
    }
};
