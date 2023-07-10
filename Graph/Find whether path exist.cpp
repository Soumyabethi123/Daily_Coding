//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    vector<int>row = {-1,1,0,0};
    vector<int>col = {0,0,1,-1};
    
    bool dfs(int r,int c,vector<vector<int>>& vis,int n,vector<vector<int>>& grid){
        
        if(grid[r][c]==2){
            
            return true;
        }
        
        
        bool ans=false;
        
        for(int i=0; i<4; i++){
            
            int a=r+row[i];
            int b=col[i]+c;
            
            if(a<n && b<n && a>=0 && b>=0 && vis[a][b]==0 && grid[a][b]!=0){
                
                vis[a][b]=1;
                
                ans=ans||dfs(a,b,vis,n,grid);
            }
        }
        
        return ans;
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        
        
        //code here
        int n=grid.size();
        
        vector<vector<int>>vis(n,vector<int>(n,0));
    
        
        for(int i=0; i<grid.size(); i++){
            
            for(int j=0; j<grid[i].size(); j++){
                
                if(grid[i][j]==1){
                    
                    vis[i][j]=1;
                    
                    return dfs(i,j,vis,n,grid);
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends
