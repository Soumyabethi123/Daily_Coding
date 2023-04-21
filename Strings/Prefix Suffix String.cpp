//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        
        unordered_map<string,int>mp;
        
        for(int i=0; i<s2.size(); i++){
            
            mp[s2[i]]++;
        }
        
        int ans=0;
        
        for(int i=0; i<s1.size(); i++){
            
            string temp=s1[i];
            
            string a="";
            
            for(int j=0; j<temp.size(); j++){
                
                a.push_back(temp[j]);
                
                if(mp.find(a) != mp.end()){
                    
                    ans++;
                    mp[a]--;
                    
                    //cout<<a<<" "<<ans<<endl;
                    
                    if(mp[a]==0){
                        
                        mp.erase(a);
                    }
                }
            }
            
            string b;
            
            for(int j=temp.size()-1; j>=0; j--){
                
                b=temp[j]+b;
                
                if(mp.find(b) != mp.end()){
                    
                    ans++;
                    mp[b]--;
                    
                    //cout<<b<<" "<<ans<<endl;
                    
                    if(mp[b]==0){
                        
                        mp.erase(b);
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
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends
