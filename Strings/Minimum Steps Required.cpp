//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    
    int n=str.size();
    
    int atob=0;
    int btoa=0;
    
    for(int i=0; i<n-1; i++){
        
        if(str[i]=='a' && str[i+1]=='b'){
            
            atob++;
        }
        else if(str[i]=='b' && str[i+1]=='a'){
            
            btoa++;
        }
    }
    
    
    return max(atob,btoa)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends
