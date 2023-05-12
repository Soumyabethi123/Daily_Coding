//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        
        int count=0;
        int flag=0;
        
        int i=0;
        while(i<n){
            
            while(i<n && arr[i]==0){
                
                i++;
                flag=1;
            }
            
            if(i<n){
                
                count++;
                while(i<n && arr[i] != 0){
                    
                    i++;
                }
            }
        }
        
        if(flag==0){
            
            return -1;
        }
        else{
            return count;
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
