//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      //code here
      
      int i=0;
      int n=S.size();
      
      long long ans=0;
      
      while(i<(n-1)){
          
          if(S[i]=='p'){
              
              if(i<(n-2) && S[i+1]=='r' && S[i+2]=='p'){
                  
                  if(X>=Y){
                      
                      ans=ans+X;
                     
                      S.erase(i,2);
                      
                      i--;
                  }
                  else{
                      
                      ans=ans+Y;
                      S.erase(i+1,2);
                  }
              }
              else if(S[i+1]=='r'){
                  
                  ans=ans+X;
                  S.erase(i,2);
                  i--;
              }
              else{
                  
                  i++;
              }
          }
          else if(S[i]=='r'){
              
              
              if(i<(n-2) && S[i+1]=='p' && S[i+2]=='r'){
                  
                  if(X>=Y){
                      
                      ans=ans+X;
                     
                      S.erase(i+1,2);
                      
                  }
                  else{
                      
                      ans=ans+Y;
                      S.erase(i,2);
                      i--;
                  }
              }
              else if(S[i+1]=='p'){
                  
                  ans+=Y;
                  S.erase(i,2);
                  i--;
              }
              else{
                  
                  i++;
              }
          }
          
          else{
              
              i++;
          }
          
          n=S.size();
      }
      
      return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends
