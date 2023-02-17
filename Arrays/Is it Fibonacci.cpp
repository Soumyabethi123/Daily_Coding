//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        
        long long sum=0;
        for(int i=0; i<K; i++){
            
            sum=sum+GeekNum[i];
        }
        
        vector<long long>arr;
        
        for(int i=0; i<K; i++){
            
            arr.push_back(GeekNum[i]);
        }
        
        arr.push_back(sum);
        
        int l=0;
        int r=K;
        
        for(int i=K+1; i<N; i++){
            
            sum=sum-arr[l];
            sum=sum+arr[r];
            
            arr.push_back(sum);
            
            l++;
            r++;
        }
        
        return arr[N-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends
