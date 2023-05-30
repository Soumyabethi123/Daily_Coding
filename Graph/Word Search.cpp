//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool ans=false;
    
    void rec(int len, vector<vector<char>>& board , string word , vector<vector<int>>&vis,int r,int c){
        
        if(len==word.size()){
            
            ans=true;
            return;
        }
        
        int n=board.size();
        int m=board[0].size();
        
        if(r+1>=0 && r+1<n && vis[r+1][c]==0 && board[r+1][c]==word[len]){
            
            vis[r+1][c]=1;
            rec(len+1,board,word,vis,r+1,c);
        }
        
        if(r-1>=0 && r-1<n && vis[r-1][c]==0 && board[r-1][c]==word[len]){
            
            vis[r-1][c]=1;
            rec(len+1,board,word,vis,r-1,c);
        }
        
        if(c+1>=0 && c+1<m && vis[r][c+1]==0 && board[r][c+1]==word[len]){
            
            vis[r][c+1]=1;
            rec(len+1,board,word,vis,r,c+1);
        }
        
        if(c-1>=0 && c-1<m && vis[r][c-1]==0 && board[r][c-1]==word[len]){
            
            vis[r][c-1]=1;
            rec(len+1,board,word,vis,r,c-1);
        }
        
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int len=0;
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(board[i][j]==word[len] && vis[i][j]==0){
                    
                    vis[i][j]=1;
                    rec(len+1,board,word,vis,i,j);
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
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
