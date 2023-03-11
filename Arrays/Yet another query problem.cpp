//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        
        vector<int> temp(N,1);
        
        for(int i=0; i<N; i++){
            
            int a=A[i];
            
            for(int j=i+1; j<N; j++){
                
                if(A[j]==a){
                    
                    temp[i]++;
                }
            }
        }
        
        vector<int>ans(num,0);
        
        for(int i=0; i<num; i++){
            
            int l=Q[i][0];
            int h=Q[i][1];
            int k=Q[i][2];
            
            for(int j=l; j<=h; j++){
                
                if(temp[j]==k){
                    
                    ans[i]++;
                }
            }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends
