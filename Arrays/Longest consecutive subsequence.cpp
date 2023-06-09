//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      
       int m=arr[0];
       for(int i=0; i<N; i++){
           
           m=max(m,arr[i]);
       }
       
       vector<int>hash(m+1,0);
       
       for(int i=0; i<N; i++){
           
           hash[arr[i]]++;
       }
       
       int ans=0;
       int len=0;
       
       for(int i=0; i<hash.size(); i++){
           
           //cout<<hash[i]<<" ";
           
           if(hash[i]!=0){
               
               len++;
           }
           else{
               ans=max(ans,len);
               len=0;
           }
       }
       
       ans=max(ans,len);
       
       return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
