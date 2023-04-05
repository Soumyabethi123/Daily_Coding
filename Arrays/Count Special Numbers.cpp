//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> a) {
        // Code here
        
          sort(a.begin(),a.end());
        unordered_map<int,int> m;
        int an=0;
        for(int i=0;i<n;i++){
            m[a[i]]++;
        }
        for(auto i:m){
            if(i.second>1){
                an+=i.second;
            }else{
                for(int j=0;j<n;j++){
                    if(a[j]>=i.first) continue;
                    else{
                        if(i.first%a[j]==0){an++; break;}
                    }
                }
            }
        }
        return an;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
