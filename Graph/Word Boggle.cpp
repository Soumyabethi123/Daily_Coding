//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:

    vector<int>row = {0,-1,-1,-1,0,1,1,1};
	vector<int>col = {1,1,0,-1,-1,-1,0,1};

    bool dfs(int r,int c,int ind,string s,vector<vector<char> >& board,int n,int m,int size){
        
        if(r<0 || c<0 || r>=n || c>=m){
            
            return false;
        }
        
        if(board[r][c] != s[ind]){
            
            return false;
        }
    
        
        if(ind==size-1){
            
            return true;
        }
        
        char t=board[r][c];
        board[r][c]='*';
        
        bool temp=false;
        
        for(int i=0; i<8; i++){
            
            int a=r+row[i];
            int b=c+col[i];
            
            temp=temp||dfs(a,b,ind+1,s,board,n,m,size);
                
            if(temp){
                
                board[r][c]=t;
                return true;
            }
        }
        
        board[r][c]=t;
        
        return temp;
    }
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    
	    int n=board.size();
	    int m=board[0].size();
	    
	    
	    
	    vector<string>ans;
	    
	    for(int i=0; i<dictionary.size(); i++){
	        
	        string temp=dictionary[i];
	        
	        //vector<vector<int>>vis(n,vector<int>(m,0));
	        
	        int ch=0;
	        
	        for(int a=0; a<n; a++){
	            
	            for(int b=0; b<m; b++){
	                
	                if(dfs(a,b,0,temp,board,n,m,temp.size())){
	                    
	                    ch=1;
	                    break;
	                }
	            }
	            if(ch==1){
	                break;
	            }
	        }
	        
	        if(ch==1){
	            
	            ans.push_back(temp);
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
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
