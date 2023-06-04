//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
     void dfs(int start, vector<int> &vis, stack<int> &s, unordered_map<int,vector<pair<int,int>>>mp) {
	    
	    vis[start] = 1;
	    
	    for(auto it : mp[start]) {
	        
	        if(!vis[it.first]) {
	            
	            dfs(it.first, vis, s, mp);
	        }
	    }
	    
	    s.push(start);
	}
	
	
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        unordered_map<int,vector<pair<int,int>>>mp;
        
        for(int i=0; i<edges.size(); i++){
            
            mp[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int>vis(N,0);
        
        stack<int>st;
        
        dfs(0,vis,st,mp);
        
        vector<int>dist(N,INT_MAX);
        
        dist[0]=0;
        
        while(!st.empty()){
            
            int top=st.top();
            st.pop();
            
            if(dist[top] != -1){
                
                for(auto it:mp[top]){
                    
                    dist[it.first] = min( dist[it.first] , dist[top]+it.second );
                }
            }
        }
        
        for(int i=0; i<N; i++){
            
            if(dist[i]==INT_MAX){
                
                dist[i]=-1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
