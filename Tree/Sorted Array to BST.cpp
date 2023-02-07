class Solution {
public:

    TreeNode* binary(vector<int>& nums,int l,int h){

        if(l > h){

            return NULL;
        }

            
            int mid=(l+h)/2;

            TreeNode *temp = new TreeNode(nums[mid]);

            temp->left=binary(nums,l,mid-1);

            temp->right=binary(nums,mid+1,h);

        return temp;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return binary(nums,0,(nums.size())-1);
    }
};
