//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        map<char,int>m;
        
        for(int i=0; i<S.size(); i++){
            
            m[S[i]]++;
        }
        
        int n=S.size();
        
       
            int i=0;
            int j=n-1;
            
            
        while(i<=j){
            
        
            while(i<=j && m[S[i]]<2){
                
                i++;
            }
            
            if(i<=j && m[S[i]]>=2){
                
                m[S[i]]--;
                S.erase(i,1);
                j--;
                
            }
            else if(i>j){
                
                return S;
            }
            
           
            
            while(j>=i && m[S[j]]<2){
                
                j--;
            }
            
            if(j>=i && m[S[j]]>=2){
                
                m[S[j]]--;
                S.erase(j,1);
                
            }
            else if(j<i){
                
                 reverse(S.begin(),S.end());
                 return S;
            }
            //return S;
            
        }
        
        return S;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
