//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int rec(int x,int y,vector<vector<int>> &M,int n,int m,vector<vector<int>> &vec){
        
        if( (x>=n) || (y>=m) || (x<0) || (y<0)){
            
            return 0;
        }
        
        if(vec[x][y] != -1){
            
            return vec[x][y];
        }
        
        int a=rec(x-1,y+1,M,n,m,vec);
        
        int b=rec(x,y+1,M,n,m,vec);
        
        int c=rec(x+1,y+1,M,n,m,vec);
        
        vec[x][y] = M[x][y] + max( max(a,b) , c);
        
        return vec[x][y];
    }
    
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int ans=INT_MIN;
        
        vector<vector<int>> vec( n+1 , vector<int> (m+1, -1)); 
        
        for(int i=0; i<n; i++){
            
            ans=max(ans,rec(i,0,M,n,m,vec));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
