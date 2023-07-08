//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    vector<vector<int>>vis(N,vector<int>(N,0));
	    
	    queue<vector<int>>q;
	    
	    int t0=TargetPos[0];
	    int t1=TargetPos[1];
	    
	    int s0=KnightPos[0];
	    int s1=KnightPos[1];
	    
	    t0--;
	    t1--;
	    s0--;
	    s1--;
	    
	    vector<int>temp;
	    temp.push_back(s0);
	    temp.push_back(s1);
	    temp.push_back(0);
	    
	    q.push(temp);
	    
	    int ans=0;
	    
	    vis[s0][s1]=1;
	    
	    vector<int>row = {2,1,2,1,-1,-2,-1,-2};
	    vector<int>col = {1,2,-1,-2,2,1,-2,-1};
	    
	    
	    while(!q.empty()){
	        
	        vector<int>front=q.front();
	        q.pop();
	        
	        
	         if(front[0]==t0 && front[1]==t1){
	             
	             ans=front[2];
	             break;
	         }
	         else{
	             
	             for(int i=0; i<8; i++){
	                 
	                 int a=front[0]+row[i];
	                 int b=front[1]+col[i];
	                 
	                 if(a>=0 && b>=0 && a<N && b<N && vis[a][b]==0){
	                     
	                     temp.clear();
	                     
	                     temp.push_back(a);
	                     temp.push_back(b);
	                     temp.push_back(front[2]+1);
	                     
	                     
	                     q.push(temp);
	                     
	                     vis[a][b]=1;
	                 }
	             }
	         }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
