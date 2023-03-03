class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int i=0;
        int n=haystack.size();

        while(i<n){

            if(haystack[i]==needle[0]){

                if(n-i >= needle.size()){

                    int flag=0;
                    int k=0;
                    int j=i;
                    while(j<n && k<needle.size()){

                        if(haystack[j] != needle[k]){

                            flag=1;
                            break;
                        }
                        j++;
                        k++;
                    }

                    if(flag==0){

                        return i;
                    }
                    else{

                        i++;
                    }

                }
                else{

                    i++;
                }
                
            }
            else{
                i++;
            }
        }

        return -1;
    }
};
