//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here   
          
          map<char,int>m;
          
          for(int i=0; i<n; i++){
              
              m[x[i]]=b[i];
          }
          
          int res=INT_MIN;
          int curr_sum=0;
          
            int start=0;
            int end=0;
            
            int mstart=0;
            int mend=0;
            
            for(int i=0; i<w.size(); i++){
              
                if(m.find(w[i]) != m.end()){
                  
                  curr_sum+=(int)m[w[i]];
                }
                else{
                  
                  curr_sum+=w[i];
                }
              
                
                
                if(res < curr_sum){
                    
                    res=curr_sum;
                    mstart=start;
                    mend=i;
                    end=i;
                }
                
                if(curr_sum < 0){
                    
                    curr_sum=0;
                    start=i+1;
                }
            }
          
          return w.substr(mstart,mend-mstart+1);
          
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends
