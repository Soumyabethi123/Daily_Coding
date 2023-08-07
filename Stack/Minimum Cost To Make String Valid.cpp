#include <bits/stdc++.h> 

int findMinimumCost(string str) {
  // Write your code here

   if(str.size()%2==1){

      return -1;
   }

   stack<char>st;

   for(int i=0; i<str.size(); i++){

      if(st.empty()){

        st.push(str[i]);
      }
      else{

         if(str[i]=='{'){

            st.push(str[i]);
         }
         else{

             if(st.top()=='{'){

               st.pop();
             }
             else{

                st.push(str[i]);
             }
         }
      }

   }

   int a=0,b=0;

   while(!st.empty()){

      if(st.top()=='{'){
        a++;
      }
      else{

        b++;
      }

      st.pop();
   }

   return ((a+1)/2) + ((b+1)/2);
}
