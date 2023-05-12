//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        
       vector<int>vis(N,0);
       
       for(int i=0; i<N; i++){
           
           if(S[i]=='1'){
               
               if(i-X < 0){
                   
                   vis[0]++;
               }
               else{
                   vis[i-X]++;
               }
               
               if(i+X < N-1){
                   
                   vis[i+X+1]--;
               }
           }
       }
       
       for(int i=1; i<N; i++){
           
           vis[i]=vis[i]+vis[i-1];
       }
       
       for(int i=0; i<N; i++){
           
           if(vis[i]==0){
               return 0;
           }
       }
       
       return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends
