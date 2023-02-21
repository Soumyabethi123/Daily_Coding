class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        
        int l=0,h=arr.size()-1;

        while(l<h){

            int mid=(l+h)/2;

            if(mid==0){

                if(arr[mid+1]==arr[mid]){

                    l=mid+1;
                }
                else{
                    return arr[mid];
                }
            }
            else if(mid==arr.size()-1){

                if(arr[mid-1]==arr[mid]){

                    h=mid-1;
                }
                else{

                    return arr[mid];
                }
            }
            else if(mid%2==0){

                if(arr[mid-1]==arr[mid]){

                    h=mid-1;
                }
                else if(arr[mid+1]==arr[mid]){

                    l=mid+1;
                }
                else{

                    return arr[mid];
                }
            }
            else{

                if(arr[mid-1]==arr[mid]){

                    l=mid+1;
                }
                else if(arr[mid+1]==arr[mid]){

                    h=mid-1;
                }
                else{
                    return arr[mid];
                }
            }
        }

        return arr[l];
    }
};
