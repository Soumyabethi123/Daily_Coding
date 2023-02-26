//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        
        int x=A.size();
        
        string B=A;
        
        reverse(B.begin(),B.end());
        
        vector<vector<int>> t (x+1,vector<int> (x+1,0));
        
        for(int i=1; i<=x; i++){
            
            for(int j=1; j<=x; j++){
                
                if(A[i-1]==B[j-1]){
                    
                    t[i][j] = 1+t[i-1][j-1];
                }
                else{
                    
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return t[x][x];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
