//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    void update(int a[], int n, int updates[], int k)
    {
        // Your code goes here
        vector<int>arr(n,0);
        
        for(int i=0; i<k; i++){
            
            int ind=updates[i]-1;
            arr[ind]++;
        }
        
        for(int i=1; i<n; i++){
            
            arr[i]=arr[i]+arr[i-1];
        }
        
        for(int i=0; i<n; i++){
            
            a[i]=arr[i];
        }
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n]={0}, updates[k]={0};
		for(int i = 0; i < k; i++)
		cin>>updates[i];
		Solution ob;
		ob.update(a, n, updates, k);
		
		for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
		
		cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends
