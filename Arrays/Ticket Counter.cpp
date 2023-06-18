//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int k) {
        // code here
        
        vector<int>v;
        
        for(int i=0; i<N; i++){
            v.push_back(i+1);
        }
        
        int i=0,j=N-1;
        int ans=v[0];
        
        while(i<j){
            
            int temp=k;
            
            while(i<j && temp--){
                
                i++;
            }
            
            if(i==j){
                
                ans=v[i];
                break;
            }
            
            temp=k;
            
            while(i<j && temp--){
                j--;
            }
            
            if(i==j){
                
                ans=v[i];
                break;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
