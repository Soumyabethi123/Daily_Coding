//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        
        int m=A[0];
        for(int i=1; i<n; i++){
            
            m=max(m,A[i]);
        }
        
        vector<vector<int> >v(m+1,vector<int>(n+1,0));
        
        int ans=0;
        
        for(int i=0; i<n; i++){
            
            for(int j=i+1; j<n; j++){
                
                int diff=A[j]-A[i];
                
                v[diff][j+1] = v[diff][i+1] + 1;
                
                ans=max(ans,v[diff][j+1]);
            }
        }
        
        return ans+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
