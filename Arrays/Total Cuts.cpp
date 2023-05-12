//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        
        vector<int>small(N,0);
        vector<int>large(N,0);
        
        int maxi=A[0];
        small[0]=A[0];
        
        for(int i=1; i<N; i++){
            
            maxi=max(maxi,A[i]);
            
            small[i]=maxi;
        }
        
        int mini=A[N-1];
        
        for(int i=N-2; i>=0; i--){
            
            large[i]=mini;
            
            mini=min(mini,A[i]);
        }
        
        int ans=0;
        
        for(int i=0; i<N-1; i++){
            
            if(small[i]+large[i] >= K){
                
                ans++;
            }
            
            //cout<<small[i]<<" "<<large[i]<<endl;
        }
        
        return ans;
    }
};
