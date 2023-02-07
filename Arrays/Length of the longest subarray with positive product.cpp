//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           
            int ans=0;
            
            int i=0,j=0;
            
            int first_neg=-1,count=0;
            
            while(j<n){
                
                if(arr[j]==0){
                    
                    i=j+1;
                    first_neg=-1;
                    count=0;
                }
                else if(arr[j] < 0){
                    
                    count++;
                    
                    if(first_neg==-1){
                        
                        first_neg=j;
                    }
                    
                }
                
                
                if(count%2==0){
                        
                    ans=max(ans,j-i+1);
                }
                else{
                        
                    ans=max(ans,j-first_neg);
                }
                
                j++;
            }
            
            return ans;
           
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends
