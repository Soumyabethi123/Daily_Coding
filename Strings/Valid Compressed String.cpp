//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        
        int i=0,j=0;
        
        int n=S.size();
        
        while(j<T.size()){
            
            if(i==n){
                
                return 0;
            }
            if(isdigit(T[j])){
                
                string temp="";
                
                while(isdigit(T[j])){
                    
                    temp.push_back(T[j]);
                    j++;
                }
                
                int d=stoi(temp);
                
                //cout<<d<<" "<<n-i<<endl;
                
                if(d <= (n-i)){
                    
                    i=i+d;
                }
                else{
                    return 0;
                }
                
            }
            else if(T[j] != S[i]){
                
                return 0;
                
            }
            else{
                
                i++;
                j++;
            }
            
        }
        
        if(i==S.size() && j==T.size()){
            
            return 1;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
