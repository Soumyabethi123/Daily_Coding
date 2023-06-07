//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    int find(int n){
        
        for(int i=2; i<=sqrt(n); i++){
            
            if(n%i==0){
                
                return i;
            }
        }
        
        return -1;
    }
  
    vector<int> leastPrimeFactor(int n) {
        // code here
        
        vector<int>ans(n+1,0);
        ans[1]=1;
        ans[2]=2;
        ans[3]=3;
        
        for(int i=4; i<=n; i++){
            
            if(i%2==0){
                
                ans[i]=2;
            }
            else{
                
                int t=find(i);
                
                if(t==-1){
                    ans[i]=i;
                }
                else{
                    ans[i]=ans[t];
                }
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
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends
