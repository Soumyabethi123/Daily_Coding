//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        queue<pair<int,int>>q;
        
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(grid[i][j]==2){
                    
                    q.push({i,j});
                }
            }
        }
        
        int ans=0;
        
        while(!q.empty()){
            
            int s=q.size();
            
            //ans++;
            int flag=0;
            
            for(int i=0; i<s; i++){
                
                int r=q.front().first;
                int c=q.front().second;
                
                q.pop();
                
                if(r-1>=0 && r-1<n && grid[r-1][c]==1){
                    
                    grid[r-1][c]=2;
                    q.push({r-1,c});
                    flag=1;
                }
                
                if(r+1>=0 && r+1<n && grid[r+1][c]==1){
                    
                    grid[r+1][c]=2;
                    q.push({r+1,c});
                    flag=1;
                }
                
                if(c-1>=0 && c-1<m && grid[r][c-1]==1){
                    
                    grid[r][c-1]=2;
                    q.push({r,c-1});
                    flag=1;
                }
                
                 if(c+1>=0 && c+1<m && grid[r][c+1]==1){
                    
                    grid[r][c+1]=2;
                    q.push({r,c+1});
                    flag=1;
                }
            }
            
            if(flag==1){
                
                ans++;
            }
        }
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(grid[i][j]==1){
                    
                    return -1;
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
