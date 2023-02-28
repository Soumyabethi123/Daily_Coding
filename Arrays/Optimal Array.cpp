//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // Code here
       
       int j = 0, sum = 0;
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            
            
            sum += a[i] - a[j];
            ans.push_back(sum);
            
            if(i%2==1){
                
                j++;
            }
        } 
        return ans;
    }
};
