//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    unordered_map<char,int>mp;
    
    int ans=0;
    
    int i=0,j=0;
    
    int n=S.size();
    
    while(j<n){
        
        if(mp.find(S[j])==mp.end()){
            
            mp[S[j]]=j;
        }
        else{
            
            int size=mp.size();
            
            ans=max(ans,size);
            
            int temp=mp[S[j]];
            
            for(int k=i; k<=temp; k++){
                
                mp.erase(S[k]);
            }
            
            i=temp+1;
            mp[S[j]]=j;
        }
        
        j++;
    }
    
    int size=mp.size();
            
    ans=max(ans,size);
    return ans;
}
