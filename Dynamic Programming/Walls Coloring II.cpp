//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        
        if(costs.size() > 1 && costs[0].size()==1){
            
            return -1;
        }
        
        int n=costs.size();
        
        int m1=costs[0][0];
        int m2=costs[0][1];
        
        for(int i=1; i<costs[0].size(); i++){
            
            if(m1 > costs[0][i]){
                
                m2=m1;
                m1=costs[0][i];
            }
            else if(m2 > costs[0][i]){
                
                m2=costs[0][i];
            }
        }
        
        //cout<<m1<<" "<<m2<<endl;
        
        
        for(int i=1; i<costs.size(); i++){
            
            for(int j=0; j<costs[i].size(); j++){
                
                
                if(costs[i-1][j]==m1){
                    
                    costs[i][j]+=m2;
                }
                else{
                    
                    costs[i][j]+=m1;
                }
                
            }
            
            m1=costs[i][0];
            m2=costs[i][1];
            
            for(int j=1; j<costs[i].size(); j++){
            
                if(m1 > costs[i][j]){
                
                    m2=m1;
                    m1=costs[i][j];
                }
                else if(m2 > costs[i][j]){
                
                    m2=costs[i][j];
                }
            }
        }
        
        
        int ans=costs[n-1][0];
        
        for(int i=1; i<costs[0].size(); i++){
            
            ans=min(ans,costs[n-1][i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends
