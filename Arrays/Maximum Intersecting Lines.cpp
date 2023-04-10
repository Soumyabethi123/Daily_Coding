// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        map<long int,long int>m;
        
        long int max1=INT_MIN;
        long int min1=INT_MAX;
        
        for(int i=0; i<N; i++){
            
            long int a=lines[i][0];
            long int b=lines[i][1];
            
            m[a]++;
            m[b+1]--;
            
            max1=max(max1,b);
            min1=min(min1,a);
        }
        
        long int ans=0;
        long int prefix=0;
        
        for(auto it : m){
            
            prefix=prefix+it.second;
            
            ans=max(ans,prefix);
        }
        
        return ans;
    }
};
