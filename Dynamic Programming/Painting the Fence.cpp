//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        int mod=1000000007;
        
        long long a=k;
        
        long long b=(k*k)%mod;
        
        if(n==1){
            
            return a;
        }
        else if(n==2){
            
            return b;
        }
        
        long long c;
        
        for(int i=3; i<=n; i++){
            
            c=( (a+b)*(k-1) )%mod;
            
            a=b;
            b=c;
        }
        
        return c;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends
