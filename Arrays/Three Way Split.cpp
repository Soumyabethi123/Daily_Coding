#include <bits/stdc++.h> 
long long threeWaySplit(int n, vector<int> arr){
    // Write your code here.

    int i=0,j=n-1;

    long long ans=0;

    long long sum1=0,sum2=0;

    while(i<j){

        if(sum1==sum2){

            ans=max(ans,sum1);
            sum1=sum1+arr[i];
            sum2=sum2+arr[j];
            i++;
            j--;
        }
        else if(sum1 < sum2){
           sum1=sum1+arr[i];
           i++;
        }
        else{
            sum2=sum2+arr[j];
            j--;
        }
    }

    if(sum1 > sum2){

        sum2=sum2+arr[j];
    }
    else if(sum1 < sum2){

        sum1=sum1+arr[i];
    }

    if(sum1==sum2){

        ans=max(ans,sum1);
    }
    
   

    return ans;
}
