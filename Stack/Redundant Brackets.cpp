#include <bits/stdc++.h> 

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char>st;

    for(int i=0; i<s.size(); i++){

        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){

            st.push(s[i]);
        }
        else if(s[i]==')'){

            int flag=0;

            while(!st.empty() && st.top()!='('){

                if(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/'){

                    flag=1;
                }

                st.pop();
            }

            if(!st.empty()){

                st.pop();
            }

            if(flag==0){

                return true;
            }
        }
    }

    return false;
}
