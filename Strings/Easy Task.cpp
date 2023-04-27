//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        // Code here
        
        vector<char>ans;
       
        for(int i=0; i<q; i++){
            
            int type=stoi(queries[i][0]);
            
            if(type==1){
                
                int ind=stoi(queries[i][1]);
                s[ind]=queries[i][2][0];
            }
            else{
                
                int left=stoi(queries[i][1]);
                int right=stoi(queries[i][2]);
                
                int k=stoi(queries[i][3]);
                
                int m[26]={0};
                
                for(int j=left; j<=right; j++){
                    
                    m[s[j]-'a']++;
                }
                
        
                for(int i=25; i>=0; i--) {
        
                     //cout<<i+'a'<<" "<<m[i]<<endl;
                     
                     if(m[i]>0 && k==1){
                         
                        
                         ans.push_back(i+'a');
                         break;
                     }
                     else if(m[i]>0){
                         
                        
                         
                         if(k>m[i]){
                             
                             k=k-m[i];
                         }
                         else{
                              ans.push_back(i+'a');
                              break;
                         }
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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends
