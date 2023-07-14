//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
        sort(arr,arr+n);
        
        int div=0;
        
        for(int i=0; i<n; i++){
            
            if(arr[i] < k){
            
                div=i;
            }
            else{
                break;
            }
        }
        
        int min1=INT_MAX;
        int max1=INT_MIN;
        int ans=arr[n-1]-arr[0];
        
        for(int i=div+1; i<n; i++){
            
            min1=min(arr[0]+k , arr[i]-k);
            
            max1=max(arr[i-1]+k , arr[n-1]-k);
            
            ans=min(ans,max1-min1);
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
