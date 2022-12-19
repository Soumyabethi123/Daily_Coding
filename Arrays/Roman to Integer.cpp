class Solution {
public:
    int romanToInt(string s) {
        
        int i=0;
        
        int ans=0;

        int n=s.size();

        while(i<n){

            if(s[i]=='I'){

                if( (i+1)<n && s[i+1]=='V'){
                    ans=ans+4;
                    i=i+2;
                }
                else if( (i+1)<n && s[i+1]=='X'){
                    ans=ans+9;
                    i=i+2;
                }
                else{
                    ans++;
                    i++;
                }
            }
            else if(s[i]=='V'){

                ans=ans+5;
                i++;
            }
            else if(s[i]=='X'){

                if( (i+1)<n && s[i+1]=='L'){

                    ans=ans+40;
                    i=i+2;
                }
                else if( (i+1)<n && s[i+1]=='C'){
                    ans=ans+90;
                    i=i+2;
                }
                else{
                    ans=ans+10;
                    i++;
                }
            }
            else if(s[i]=='L'){

                ans=ans+50;
                i++;
            }
            else if(s[i]=='C'){

                if( (i+1)<n && s[i+1]=='D'){

                    ans=ans+400;
                    i=i+2;
                }
                else if( (i+1)<n && s[i+1]=='M'){

                    ans=ans+900;
                    i=i+2;
                }
                else{
                    ans=ans+100;
                    i++;
                }
            }
            else if(s[i]=='D'){

                ans=ans+500;
                i++;
            }
            else{

                ans=ans+1000;
                i++;
            }
        }

        return ans;
    }
};
