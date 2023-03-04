//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        int left_max=arr[0];
        left[0]=left_max;
        
        for(int i=1; i<n; i++){
            
            left_max=max(left_max,arr[i]);
            
            left[i]=left_max;
        }
        
        left_max=arr[n-1];
        right[n-1]=left_max;
        
        for(int i=n-2; i>=0; i--){
            
            left_max=max(left_max,arr[i]);
            
            right[i]=left_max;
        }
        
        long long ans=0;
        
        for(int i=0; i<n; i++){
            
            ans+=( min(left[i],right[i]) - arr[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
