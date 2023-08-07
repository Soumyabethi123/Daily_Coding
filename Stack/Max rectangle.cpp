//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int>st1,st2;

        int n=heights.size();

        vector<int>next(n,0);
        vector<int>prev(n,0);

        st1.push(n);

        for(int i=n-1; i>=0; i--){

            while(st1.top()<n && heights[st1.top()] >= heights[i]){

                st1.pop();      
            }
            
            next[i]=st1.top();
            st1.push(i);
        }

        st2.push(-1);

        for(int i=0; i<n; i++){

            while(st2.top()>=0 && heights[st2.top()] >= heights[i]){

                st2.pop();
            }

            prev[i]=st2.top();
            st2.push(i);
        }

        int max1=0;

        for(int i=0; i<n; i++){

            max1=max(max1,heights[i]*(next[i]-prev[i]-1));
        }

        return max1;
    }
    
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        vector<int>temp(m,0);
        
        int maxi=0;
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(M[i][j]==0){
                    
                    temp[j]=0;
                }
                else{
                    
                    temp[j]+=M[i][j];
                }
            }
            
            int a=largestRectangleArea(temp);
            
            maxi=max(maxi,a);
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
