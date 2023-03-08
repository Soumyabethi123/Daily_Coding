class Solution {
public:

    long int find(vector<int>& piles,int mid){

         long int hr=0;

         for(int i=0; i<piles.size(); i++){

             hr+=ceil(piles[i]/double(mid));
         }

         return hr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        long int l=1;
        long int r=*(max_element(piles.begin(), piles.end()));
        int ans=-1;

        while(l<=r){

            long int mid=(l+r)/2;

            long int hours=find(piles,mid);

            if(hours<=h){

                 ans=mid;
                 r=mid-1;
            }
            else{

                l=mid+1;
            }

        }

        return ans;
    }
};
