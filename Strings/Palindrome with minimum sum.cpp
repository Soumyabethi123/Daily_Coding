//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        
        int i=0;
        int n=s.size();
        int j=n-1;
        
        while(i<j){
            
            if(s[i] != s[j]){
                
                if(s[i]=='?' && s[j]!='?'){
                    
                    s[i]=s[j];
                }
                else if(s[i]!='?' && s[j]=='?'){
                    
                    s[j]=s[i];
                }
                else{
                    
                    return -1;
                }
            }
            
            i++;
            j--;
        }
        
        int ans=0;
        char last='?';
        
        i=0;
        j=n-1;
        
        while(i<n){
            
            if(s[i]=='?'){
                
                if(last != '?'){
                    
                    s[i]=last;
                    s[j]=last;
                }
            }
            else{
                
                if(last != '?'){
                    
                    ans=ans+ abs((s[i]-'a')-(last-'a'));
                
                }
                
                last=s[i];
            }
            
            i++;
            j--;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
