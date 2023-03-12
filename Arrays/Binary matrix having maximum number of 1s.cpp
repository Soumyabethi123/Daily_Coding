//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        
        int i=0,j=N-1;
        
        int row=0;
        int ans=0;
        
        while(i<N && j>=0){
            
            if(mat[i][j]==1){
                
                row=i;
                ans++;
                
                j--;
            }
            else{
                
                i++;
            }
        }
        
        vector<int>ans2;
        ans2.push_back(row);
        ans2.push_back(ans);
        
        return ans2;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends
