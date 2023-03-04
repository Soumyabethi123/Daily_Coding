//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:

		int min_operations(vector<int>a){
		    // Code here
		    int n=a.size();
		    vector<int>dp(n,1);
       
            int ans=0;
       
            for(int i=1; i<n; i++){
           
                for(int j=0; j<i; j++){
               
                   if(a[i] >= a[j] && (i-j) <= a[i]-a[j] ){
                   
                      dp[i] = max(dp[i],dp[j]+1);
                    }
                }
           
                ans=max(ans,dp[i]);
            
            }
            
            if(ans==0){
                
                ans=1;
            }
       
            return a.size()-ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans  = ob.min_operations(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
