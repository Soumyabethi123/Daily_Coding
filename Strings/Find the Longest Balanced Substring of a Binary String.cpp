class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        
        int c0=0,c1=0;
        
        int ans=0;
        int flag=0;
        
        for(int i=0; i<s.size(); i++){
            
            if(i==0 && s[i]=='0'){
                
                flag=1;
                c0++;
            }
            else if(flag==0 && s[i]=='1'){
                
                continue;
            }
            else if(s[i]=='0' && s[i-1]=='1'){
                
                c0=1;
                c1=0;
                flag=1;
            }
            else if(s[i]=='0'){
                
                c0++;
                flag=1;
            }
            else{
                c1++;
            }
            
            ans=max(ans,min(c0,c1));
        }
        
        return ans*2;
    }
};
