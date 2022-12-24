//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        
       
        sort(arr.begin(),arr.end());
        
        vector<vector<int>>ans;
        
        
        for(int i=0; i<arr.size()-3; i++){
            
            for(int j=i+1; j<arr.size()-2; j++){
                
                int p=j+1;
                int q=arr.size()-1;
                
                while(p<q){
                    
                    
                    if( (arr[p]+arr[q]) < (k - (arr[i] + arr[j]) )){
                        
                        p++;
                    }
                    else if ( (arr[p]+arr[q])  >  (k - (arr[i] + arr[j]) ) ){
                        
                        q--;
                    }
                    else{
                        
                        vector<int>temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[p]);
                        temp.push_back(arr[q]);
                    
                        ans.push_back(temp);
                        
                        while(p<q && arr[p]==temp[2]){
                            
                            p++;
                        }
                        
                        while(p<q && arr[q]==temp[3]){
                            
                            q--;
                        }
                        
                    }
                }
                
                while(j<arr.size()-2 && arr[j]==arr[j+1]){
                    
                    j++;
                }
                
            
            }
            
            while(i<arr.size()-3 && arr[i]==arr[i+1]){
                    
                i++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
