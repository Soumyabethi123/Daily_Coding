//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    vector<int>row = {-1,1,0,0};
    vector<int>col = {0,0,1,-1};
    
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        
        vector<vector<int>>vis(N,vector<int>(M,0));
        
        int dist=0;
        queue<pair<int,pair<int,int>>>q;
    
        q.push({0,{0,0}});
        
        vis[0][0]=1;
        int flag=0;
        
        int ans=INT_MAX;
        
        while(!q.empty()){
            
            auto temp=q.front();
            
            q.pop();
            
            int r=temp.second.first;
            int c=temp.second.second;
            int dist=temp.first;
            
            if(r==X && c==Y){
                
                flag=1;
                ans=min(ans,dist);
                continue;
            }
            
           
            for(int i=0; i<4; i++){
                
                int a=r+row[i];
                int b=c+col[i];
                
                if(a<N && b<M && a>=0 && b>=0 && vis[a][b]==0 && A[a][b]==1){
                    
                    vis[a][b]=1;
                
                    q.push({dist+1,{a,b}});
                    
                }
            }
        
        }
        
        if(flag==0){
            return -1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
