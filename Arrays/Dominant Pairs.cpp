//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    int find(vector<int> &arr,int size,int target){
        
        int l=0;
        int h=size-1;
        
        if(target < arr[l]){
            
            return -1;
        }
        else if(target >= arr[h]){
            
            return size;
        }
        else{
            
            int ans=-1;
            
            while(l<=h){
                
                int mid=(l+h)/2;
                
                if(arr[mid-1] <= target && arr[mid]>target){
                    
                    ans=mid;
                    break;
                }
                else if( arr[mid] <= target && arr[mid+1] > target){
                    
                    ans=mid+1;
                    break;
                }
                else if(arr[mid] <= target){
                    
                    l=mid+1;
                }
                else{
                    
                    h=mid-1;
                }
            }
            
            if(ans==-1){
                
                return l+1;
            }
            return ans;
        }
    }
    
    
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        
        vector<int>temp1;
        vector<int>temp2;
        
        for(int i=0; i<n/2; i++){
            
            temp1.push_back(arr[i]);
        }
        
        for(int i=n/2; i<n; i++){
            
            temp2.push_back(5*arr[i]);
        }
        
        sort(temp2.begin(),temp2.end());
        
        sort(temp1.begin(),temp1.end(),greater<int>());
        
        int ans=0;
        
        for(int i=0; i<temp1.size(); i++){
            
            int temp=find(temp2,temp2.size(),temp1[i]);
            
            //cout<<temp<<endl;
            
            if(temp==-1){
                break;
            }
            else{
                ans=ans+temp;
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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends
