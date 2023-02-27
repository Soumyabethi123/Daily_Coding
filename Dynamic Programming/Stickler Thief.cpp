//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int find(int arr[],int n){
        
        if(n<=0){
            
            return 0;
        }
        else{
            
            return max(arr[n-1]+find(arr,n-2) , find(arr,n-1));
        }
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n,0);
        
        dp[0]=arr[0];
        
        dp[1]=max(arr[1],arr[0]);
        
        for(int i=2; i<n; i++){
            
            dp[i]= max(arr[i]+dp[i-2] , dp[i-1]);
        }
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
