//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      map<int,int>adj;
      
      for(int i=0; i<Edge.size(); i++){
          
          if(Edge[i] != -1){
              
              adj[Edge[i]]+=i;
          }
      }
      
      int ans=-1;
      int mw = 0;
      
      map<int,int>::reverse_iterator it;
      
      for(it=adj.rbegin(); it!=adj.rend(); it++){
          
          if(mw < it->second){
              
              mw=it->second;
              ans=it->first;
          }
      }
      
      if(ans==-1){
          
          return 0;
      }
      
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends
