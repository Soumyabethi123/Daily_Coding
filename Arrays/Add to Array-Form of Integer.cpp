class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
         vector<int>ans;

         int i=num.size()-1;
         int c=0;

        while(k>0 && i>=0){

            int n=k%10;
            int sum=c+num[i]+n;

            if(sum > 9){

                ans.push_back(sum%10);
                c=sum/10;
            }
            else{

                ans.push_back(sum);
                c=0;
            }
            
            i--;
            k=k/10;
        }

        while(k>0){

            int sum=c+(k%10);

            if(sum > 9){

                ans.push_back(sum%10);
                c=sum/10;
            }
            else{

                ans.push_back(sum);
                c=0;
            }

            k=k/10;
        }

        if(i<0 && c>0){

            ans.push_back(c);
            c=0;
        }
        else if(c>0){

            while(i>=0 && c>0){

                int sum=c+num[i];

                if(sum > 9){

                ans.push_back(sum%10);
                c=sum/10;
            }
            else{

                ans.push_back(sum);
                c=0;
            }

                i--;

            }

            if(c>0){

                ans.push_back(c);
                c=0;
            }
        }


       while(i>=0){

            ans.push_back(num[i]);
            i--;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
