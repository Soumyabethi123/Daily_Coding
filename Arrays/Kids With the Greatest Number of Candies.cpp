class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int m=candies[0];

        for(int i=1; i<candies.size(); i++){

            m=max(m,candies[i]);
        }

        vector<bool>ans;

        for(int i=0; i<candies.size(); i++){

            if(candies[i]+extraCandies < m){
                ans.push_back(0);
            }
            else{
                ans.push_back(1);
            }
        }

        return ans;
    }
};
