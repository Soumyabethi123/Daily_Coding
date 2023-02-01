class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        string temp1=str1+str2;
        string temp2=str2+str1;

        if(temp1==temp2){

            return str1.substr(0,__gcd(str1.length() , str2.length() ));
        }

        return "";
    }
};
