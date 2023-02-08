//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      
      vector<long long int>ans;
      
      int s1=0,s2=0;
      
      int arr1[n+1]={0};
      int arr2[n+1]={0};
      
      long long int tot=n*n;
      
      for(int i=0; i<k; i++){
          
          int r=arr[i][0]-1;
          int c=arr[i][1]-1;
          
          if(i==0){
              
              tot=tot-n-(n-1);
              
              ans.push_back(tot);
              
              s1++;
              s2++;
              
              arr1[r]=1;
              arr2[c]=1;
          }
          else{
              
              long int temp=0;
              
              int flag1=0;
              int flag2=0;
              
              if(arr1[r]==0){
                  
                  flag1=1;
                  temp=temp+(n-s2);
              }
              
              if(arr2[c]==0){
                  
                  flag2=1;
                  temp=temp+(n-s1);
              }
              
              if(flag1==1){
                  
                  s1++;
              }
              
              if(flag2==1){
                  
                  s2++;
              }
              
              arr1[r]=1;
              arr2[c]=1;
              
              if( (flag1==0 && flag2==1) || (flag1==1 && flag2==0) ){
                  
                  tot=tot-temp;
              }
              else if(flag1==1 && flag2==1){
                  
                   tot=tot-(temp-1);
              }
             
              ans.push_back(tot);
              
          }
      }
      
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends
