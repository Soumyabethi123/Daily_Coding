//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        
        string st="1";
        
        for(int i=1; i<n; i++){
            
            string temp="";
            
            int count=1;
            char prev=st[0];
            
            for(int j=1; j<st.size(); j++){
                
                if(st[j]==prev){
                    
                    count++;
                }
                else{
                    
                    temp=temp+to_string(count);
                    temp.push_back(prev);
                    
                    prev=st[j];
                    count=1;
                }
            }
            
            temp=temp+to_string(count);
            temp.push_back(prev);
            
            st=temp;
        }
        
        return st;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
