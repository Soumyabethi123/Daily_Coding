//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &inte,int k){
        // Code here
        
        int m=0;
        
        for(int i=0; i<n; i++){
            
            m=max(m,inte[i][1]);
        }
        
        vector<int>freq(m+2,0);
        
        for(int i=0; i<n; i++){
            
            freq[inte[i][0]]++;
            freq[inte[i][1] + 1]--;
        }
        
        for(int i=1; i<m+2; i++){
            
            freq[i]=freq[i-1]+freq[i];
        }
        
        int ans=-1;
        
        for(int i=m+1; i>=0; i--){
            
            if(freq[i]>=k){
                
                ans=i;
                break;
            }
        }
        
        return ans;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
