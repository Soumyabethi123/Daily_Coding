//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        map<char,int>m;
        
        for(int i=0; i<s.size(); i++){
            
            m[s[i]]++;
        }
        
        int ans=s.size();
        
        string temp="balloon";
        
        for(int i=0; i<temp.size(); i++){
            
            //cout<<m[temp[i]]<<endl;
            
            if(temp[i]=='b' || temp[i]=='a' || temp[i]=='n'){
                
                ans=min(ans,m[temp[i]]);
            }
            else{
                
                ans=min(ans,m[temp[i]]/2);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
