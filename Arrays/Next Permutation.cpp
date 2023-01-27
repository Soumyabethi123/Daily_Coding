class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int ind1,ind2;
        int n=nums.size();

        int flag=0;

        for(int i=n-2; i>=0; i--){

            if(nums[i] < nums[i+1]){

                ind1=i;
                flag=1;
                break;
            }
        }

        if(flag==0){

            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1; i>=0; i--){

            if(nums[i] > nums[ind1]){

                ind2=i;
                break;
            }
        }

        int temp=nums[ind1];
        nums[ind1]=nums[ind2];
        nums[ind2]=temp;

        int i=ind1+1,j=n-1;
        while(i<j){

            int temp1=nums[i];
            nums[i]=nums[j];
            nums[j]=temp1;

            i++;
            j--;
        }
    }
};
