//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        
        int left=0,up=0;
        int mnx=0,mny=0;
        int mxx=0,mxy=0;
        
        for(int i=0; i<s.size(); i++){
            
            if(s[i]=='L'){
                
                left++;
            }
            else if(s[i]=='R'){
                
                left--;
            }
            else if(s[i]=='U'){
                
                up--;
            }
            else{
                up++;
            }
            
            mnx=min(mnx,left);
            mxx=max(mxx,left);
            
            mny=min(mny,up);
            mxy=max(mxy,up);
            
        }
        
        
        if(abs(mnx) + mxx < m && abs(mny) + mxy < n ){
            
            return 1;
        }
        
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
