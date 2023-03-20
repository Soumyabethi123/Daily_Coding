//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        
        queue<pair<int,int>>q;
        
        for(int i=0; i<N; i++){
            
            for(int j=0; j<M; j++){
                
                if(grid[i][j]=='X'){
                    
                    q.push({i,j});
                }
            }
        }
        
        int ans=0;
        
        while(!q.empty()){
            
            int s=q.size();
            ans++;
            
            for(int i=0; i<s; i++){
                
                int r=q.front().first;
                int c=q.front().second;
                
                q.pop();
                
                int ri[4]={0,0,1,-1};
                int ci[4]={1,-1,0,0};
                
                for(int i=0; i<4; i++){
                    
                    int newr=r+ri[i];
                    int newc=c+ci[i];
                    
                    if(newr<N && newr>=0 && newc<M && newc>=0){
                        
                        if(grid[newr][newc]=='Y'){
                            
                            return ans;
                        }
                        else if(grid[newr][newc]=='O'){
                            
                            grid[newr][newc]='X';
                            q.push({newr,newc});
                        }
                    }
                }
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends
