//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        
        set<int>s;
        
        for(int i=0; i<N; i++){
            
            s.insert(frogs[i]);
        }
        
        int ans=0;
        
        for(int i=1; i<=leaves; i++){
            
            int flag=0;
            
            for(int j=1; j*j<=i; j++){
                
                if(i%j==0){
                    
                    if(s.find(j)!=s.end()){
                        
                        flag=1;
                        break;
                    }
                    else if(s.find(i/j) != s.end()){
                        
                        flag=1;
                        break;
                    }
                }
            }
            
            if(flag==0){
                
                ans++;
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
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends
