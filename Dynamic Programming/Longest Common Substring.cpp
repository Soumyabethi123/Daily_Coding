//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int x, int y)
    {
        // your code here
        
        vector<vector<int>> t (x+1,vector<int> (y+1,0));
        
        int ans=0;
        
        for(int i=1; i<=x; i++){
            
            for(int j=1; j<=y; j++){
                
                if(s1[i-1]==s2[j-1]){
                    
                    t[i][j] = 1+t[i-1][j-1];
                    ans=max(ans,t[i][j]);
                }
                else{
                    
                    t[i][j] = 0;
                }
            }
        }
        
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
