class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int start=1;

        vector<int>temp;

        int i=0;
        int n=arr.size();

        while(i<n){

            if(arr[i]==start){

                start++;
                i++;
            }
            else{

                temp.push_back(start);
                start++;
            }
        }

        if(temp.size() < k){

            int n2=temp.size();

            if(n2==0){

                return arr[n-1]+k;
            }
            else{

                return arr[n-1]-n2+k;
            }
        }
        else{

            return temp[k-1];
        }
    }
};
