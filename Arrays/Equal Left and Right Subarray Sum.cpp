//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        // code here
        
         if(N==1){
            return N;
        }
        
        vector<int> leftA(N,0);
        
        vector<int> leftR(N,0);
        
        leftA[0] = 0;
        leftA[1]=A[0];
        
        for(int i=2;i<N;i++){
            
            leftA[i] = leftA[i-1]+A[i-1];
            
        }
        
        leftR[N-1]=0;
        leftR[N-2] = A[N-1];
        
        for(int i=N-3;i>=0;i--){
            
            leftR[i] = leftR[i+1]+A[i+1];
        }
        
        for(int i=0; i<N; i++){
            
            if(leftA[i]==leftR[i]){
                return i+1;
            }
            
            
            
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
