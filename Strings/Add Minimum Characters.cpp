//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    /*int check(string str,int size){
        
        int i=0;
        int j=size-1;
        
        while(i<j){
            
            if(str[i]!=str[j]){
                
                return 1;
            }
            
            i++;
            j--;
        }
        
        return 0;
    }*/
    
    int addMinChar(string str){    
        //code here
        int n=str.size();
        
        int i=0;
        int j=n-1;
        
        while(i<j){
            
            if(str[i]==str[j]){
                
                int x=i;
                int y=j;
                
                while(x<y && str[x]==str[y]){
                    
                    x++;
                    y--;
                }
                
                if(x>=y){
                    
                    i=x;
                    j=y;
                }
                else{
                    
                    j--;
                }
            }
            else{
                
                j--;
            }
        }
        
        int x=n-1-j;
        int y=i;
        
        return x-y;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
