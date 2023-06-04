//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        vector<int>adj[N];
        
        for(int i=0; i<edges.size(); i++){
            
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(N,0);
        vector<int>parent(N,-1);
        
      
                queue<int>q;
                q.push(src);
                vis[src]=1;
                parent[src]=-1;
                
                while(!q.empty()){
                    
                    int front=q.front();
                    q.pop();
                    
                    for(auto it:adj[front]){
                        
                        if(vis[it]==0){
                            
                            vis[it]=1;
                            parent[it]=front;
                            q.push(it);
                        }
                    }
                }
            
        
        
        vector<int>ans(N,-1);
        
        for(int i=0; i<N; i++){
            
            if(i==src){
                
                ans[i]=0;
            }
            else{
                
                int node=i;
                int count=0;
                int flag=0;
                
                while(node!=src){
                    
                    node=parent[node];
                    
                    if(node==-1){
                        
                        flag=1;
                        break;
                    }
                    count++;
                }
                
                if(flag==1){
                    
                    ans[i]=-1;
                }
                else{
                    ans[i]=count;
                }
                
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
