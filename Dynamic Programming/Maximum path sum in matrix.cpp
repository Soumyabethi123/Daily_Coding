//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
    
        
        for(int i=1; i<N; i++){
            
            for(int j=0; j<N; j++){
                
                int f=0,s=0,t=0;
                
                if(i-1>=0 && i-1<N && j-1>=0 && j-1<N){
                    
                    f=Matrix[i-1][j-1];
                }
                
                if(i-1>=0 && i-1<N){
                    
                    s=Matrix[i-1][j];
                }
                
                if(i-1>=0 && i-1<N && j+1>=0 && j+1<N){
                    
                    t=Matrix[i-1][j+1];
                }
                
                Matrix[i][j]+= ( max( f , max(s,t) ) );
            }
        }
        
        int ans=Matrix[N-1][0];
        
        for(int i=1; i<N; i++){
            
            ans=max(ans,Matrix[N-1][i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
