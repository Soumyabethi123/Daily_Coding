//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long int find(int coins[],int n, int sum, vector<vector<long int>>&dp){
        
        if(sum==0){
            
            dp[n][sum]=1;
            return 1;
        }
        
        if(n==0){
            
            return 0;
        }
        
        if(dp[n][sum] == -1){
            
            if(coins[n-1] <= sum){
                
                dp[n][sum] = find(coins,n-1,sum,dp) + find(coins,n,sum-coins[n-1],dp);
            }
            else{
                
                dp[n][sum] = find(coins,n-1,sum,dp);
            }
        }
        
        return dp[n][sum];
    }
    
    long long int count(int coins[], int N, int sum) {

        // code here.
        
        vector<vector<long int>>dp(N+1,vector<long int>(sum+1,-1));
        
        return find(coins,N,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
