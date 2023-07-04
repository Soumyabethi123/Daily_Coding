class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(n==0){

            return;
        }

        if(m==0){

            for(int i=0; i<nums1.size(); i++){

                nums1[i]=nums2[i];
            }

            return;
        }

        int i=m+n-1;

        int j=n-1;

        int k=m-1;

        while(k>=0 && j>=0){

            if(nums1[k] > nums2[j]){

                nums1[i]=nums1[k];
                i--;
                k--;
            }
            else{

                nums1[i]=nums2[j];
                i--;
                j--;
            }
        }

        while(j>=0){

            nums1[i]=nums2[j];
            i--;
            j--;
        }
        
    }
};
