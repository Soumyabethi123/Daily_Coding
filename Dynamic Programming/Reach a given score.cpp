//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function

long long int solve(long long int n,long long int prev){
    
    if(n<0){
        
        return 0;
    }
    else if(n==0){
        
        return 1;
    }
    
    long long a=0,b=0,c=0;
    
    if(prev <= 3){
        
        a=solve(n-3,3);
    }
    
    if(prev <= 5){
        
        b=solve(n-5,5);
    }
    
    if(prev <= 10){
        
        c=solve(n-10,10);
    }
    
    return a+b+c;
}


long long int count(long long int n)
{
    return solve(n,3);
    
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
