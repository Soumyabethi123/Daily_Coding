//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        
        long long ans=0;
        int m=INT_MAX;
        
        long long len=0;
        
        for(int i=0; i<N; i++){
            
            if(B[i] > 1){
                
            
            long long temp=B[i]/2;
            
            ans=ans+(temp*2*A[i]);
            
            len=len+temp;
            
            m=min(m,A[i]);
            
            }
        }
        
        if(len%2==1){
            
            ans=ans-(m*2);
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
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends
