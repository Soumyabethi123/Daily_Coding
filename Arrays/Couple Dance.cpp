#include <bits/stdc++.h> 
int maxTeams(int n, string s){
    // Write your code here.

    int c0=0,c1=0;

    for(int i=0; i<n; i++){

        if(s[i]=='0'){
            c0++;
        }
        else{
            c1++;
        }
    }

    return min(c0,c1);
}
