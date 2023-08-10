//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        
        stack<int>st;
        
        int i=0;
      
        while(i<s.size()){
            
            
            if(st.empty() || s[i]=='('){
                
                st.push(i);
            }
            else{
                
                if(s[st.top()]=='('){
                    
                    st.pop();
                }
                else{
                    
                    st.push(i);
                }
            }
            
            i++;
        }
        
        if(st.empty()){
            
            return s.size();
        }
        
        int ind=st.top();
        int ans=s.size()-ind-1;
        
        st.pop();
        
        while(!st.empty()){
            
            ans=max(ans,ind-st.top()-1);
            ind=st.top();
            st.pop();
            
        }
        ans=max(ans,ind);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends
