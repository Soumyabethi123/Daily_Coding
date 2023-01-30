class Solution {
public:
    string reverseVowels(string s) {
        
        int i=0,j=s.size()-1;

        while(i<j){

            while(i<j && ( s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U') ){

                i++;
            }

            while(i<j && ( s[j]!='a' && s[j]!='e' && s[j]!='i' && s[j]!='o' && s[j]!='u' && s[j]!='A' && s[j]!='E' && s[j]!='I' && s[j]!='O' && s[j]!='U') ){

                j--;
            }
            
            cout<<i<<" "<<j<<endl;

            if(i<j){

                cout<<s[i]<<" "<<s[j]<<endl;
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                
                i++;
                j--;
            }
            
        }

        return s;
    }
};
