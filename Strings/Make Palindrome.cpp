//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        map<string,int>mp;
        
        for(int i=0; i<n; i++){
            
            mp[arr[i]]++;
        }
        
        if(n%2==0){
            
            for(int i=0; i<n; i++){
            
                string temp=arr[i];
                reverse(temp.begin(),temp.end());
                
                if(mp.find(temp) == mp.end()){
                    
                    return 0;
                }
                else{
                    
                    mp[temp]--;
                    
                    if(mp[temp]==0){
                        mp.erase(temp);
                    }
                }
            }
            
            return 1;
        }
        else{
            
            int c=0;
            
            for(int i=0; i<n; i++){
            
                string temp=arr[i];
                reverse(temp.begin(),temp.end());
                
                if(mp.find(temp) == mp.end()){
                    
                    if(c==0){
                        
                        for(int j=0; j<temp.size(); j++){
                            
                            if(temp[j] != arr[i][j]){
                                
                                return 0;
                            }
                        }
                        
                        c=1;
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    
                    mp[temp]--;
                    
                    if(mp[temp]==0){
                        mp.erase(temp);
                    }
                }
            }
            
            return 1;
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
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends
