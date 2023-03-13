//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void dfs(int x,int y,vector<vector<char>> mat , vector<vector<int>>&vis,int n,int m){
        
        vis[x][y]=1;
        
        int delr[4]={-1,+1,0,0};
        int delc[4]={0,0,-1,+1};
        
        for(int i=0; i<4; i++){
            
            int nr=x+delr[i];
            int cr=y+delc[i];
            
            if(nr>=0 && nr<n && cr>=0 && cr<m && mat[nr][cr]=='O' && vis[nr][cr]==0){
                
                dfs(nr,cr,mat,vis,n,m);
            }
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            
             if(vis[i][0]==0 && mat[i][0]=='O'){
                 
                 dfs(i,0,mat,vis,n,m);
             }
             
             if(vis[i][m-1]==0 && mat[i][m-1]=='O'){
                 
                 dfs(i,m-1,mat,vis,n,m);
             }
        }
        
        
        for(int j=0; j<m; j++){
            
            if(vis[0][j]==0 && mat[0][j]=='O'){
                
                dfs(0,j,mat,vis,n,m);
            }
            
            if(vis[n-1][j]==0 && mat[n-1][j]=='O'){
                
                dfs(n-1,j,mat,vis,n,m);
            }
        }
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(mat[i][j]=='O' && vis[i][j]==0){
                        
                    mat[i][j]='X';
                }
                
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
