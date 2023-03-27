//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int find(int price[],int index,int size,vector<vector<int>>&dp){
        
        if(index==0){
            
            return size*price[0];
        }
        
        if(dp[index][size]!=-1){
            
            return dp[index][size];
        }
        
        int notcut=find(price,index-1,size,dp);
        int cut=INT_MIN;
        int len=index+1;
        
        if(len<=size){
            
            cut = price[index] + find(price,index,size-len,dp);
        }
        
        dp[index][size]=max(cut,notcut);
        
        return dp[index][size];
    }
    
    int cutRod(int price[], int n) {
        //code here
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        return find(price,n-1,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
