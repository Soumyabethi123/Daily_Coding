class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int i=0,j=0;

        string ans="";

        while(i<word1.size() || j<word2.size()){

            if(i>=word1.size()){

               
            }
            else{

                ans.push_back(word1[i]);
                i++;
            }

            if(j>=word2.size()){

                
            }
            else{

                ans.push_back(word2[j]);
                j++;
            }
        }

        return ans;
    }
};
