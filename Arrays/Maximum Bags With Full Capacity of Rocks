class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int adt) {
        
        vector<int>diff;

        int ans=0;

        for(int i=0; i<capacity.size(); i++){

            if(capacity[i]-rocks[i] != 0){

                diff.push_back(capacity[i]-rocks[i]);
            }
            else{

                ans++;
            }
        }

        sort(diff.begin(),diff.end());

        int i=0;
        while(i<diff.size() && adt > 0){

            if(adt >= diff[i]){
                 adt=adt-diff[i];
            }
            else{
                break;
            }
        
            ans++;
            i++;
        }

        return ans;

    }
};
