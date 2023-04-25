class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>left(n,1);
        vector<int>right(n,1);

        int lprd=nums[0];
        
        for(int i=1; i<n; i++){

            left[i]=lprd;
            lprd=lprd*nums[i];
        }

        int rprd=nums[n-1];
        for(int i=n-2; i>=0; i--){

            right[i]=rprd;
            rprd=rprd*nums[i];
        }

        vector<int>ans;

        for(int i=0; i<n; i++){

            ans.push_back(left[i]*right[i]);
        }

        return ans;
    }
};
