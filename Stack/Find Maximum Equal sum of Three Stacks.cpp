//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        
        int sum1=S1[N1-1],sum2=S2[N2-1],sum3=S3[N3-1];
        
        int ans=0;
        
        int i=N1-1,j=N2-1,k=N3-1;
        
        while(i>=0 && j>=0 && k>=0){
            
          
            if(sum1==sum2 && sum2==sum3){
                
                ans=sum1;
                
                i--;
                j--;
                k--;
                
                if(i>=0){
                    sum1=sum1+S1[i];
                }
                
                if(j>=0){
                    sum2=sum2+S2[j];
                }
                
                if(k>=0){
                    sum3=sum3+S3[k];
                }
                
            }
            else{
                
                int m=min(sum1,sum2);
                m=min(m,sum3);
                
                if(sum1==m){
                    
                    i--;
                    if(i>=0){
                    sum1=sum1+S1[i];
                }
                }
                
                if(sum2==m){
                    
                    j--;
                    if(j>=0){
                    sum2=sum2+S2[j];
                }
                }
                
                if(sum3==m){
                    
                    k--;
                    if(k>=0){
                    sum3=sum3+S3[k];
                }
                }
            
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
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
