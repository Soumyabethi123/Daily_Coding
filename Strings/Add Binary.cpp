class Solution {
public:
    string addBinary(string a, string b) {
        
        string ans="";

        int i=a.size()-1;
        int j=b.size()-1;

        int c=0;

        while(i>=0 && j>=0){

            if(c==0 && b[j]=='0' && a[i]=='0'){

               ans.push_back('0');
               c=0;
            }
            else if(c==1 && b[j]=='0' && a[i]=='0'){

                ans.push_back('1');
                c=0;
            }
            else if(b[j]=='1' && a[i]=='0' && c==0){
                
                ans.push_back('1');
                c=0;

            }
            else if(b[j]=='0' && a[i]=='1' && c==0){

                ans.push_back('1');
                c=0;
            }
            else if(b[j]=='1' && a[i]=='0' && c==1){
                
                ans.push_back('0');
                c=1;

            }
            else if(b[j]=='0' && a[i]=='1' && c==1){

                ans.push_back('0');
                c=1;
            }
            else if(b[j]=='1' && a[i]=='1' && c==0){

                ans.push_back('0');
                c=1;
            }
            else{

                ans.push_back('1');
                c=1;
            }

            i--;
            j--;
        }

        if(i>=0){

            while(i>=0){

                if(c==0 && a[i]=='0'){

                    ans.push_back('0');
                    c=0;
                }
                else if(c==1 && a[i]=='0'){

                    ans.push_back('1');
                    c=0;
                }
                else if(c==0 && a[i]=='1'){

                    ans.push_back('1');
                    c=0;
                }
                else{

                    ans.push_back('0');
                    c=1;
                }

                i--;
            }
        }


        if(j>=0){

            while(j>=0){

                if(c==0 && b[j]=='0'){

                    ans.push_back('0');
                    c=0;
                }
                else if(c==1 && b[j]=='0'){

                    ans.push_back('1');
                    c=0;
                }
                else if(c==0 && b[j]=='1'){

                    ans.push_back('1');
                    c=0;
                }
                else{

                    ans.push_back('0');
                    c=1;
                }

                j--;
            }
        }

        if(c==1){

            ans.push_back('1');
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
