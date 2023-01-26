//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        int arr1[26]={0}; //upper
        int arr2[26]={0};  // lower
        
        for(int i=0; i<n; i++){
            
            if(isupper(str[i])){
                
                arr1[str[i]-'A']++;
            }
            else{
                
                arr2[str[i]-'a']++;
            }
        }
        
        int i=0,j=0;
        
        int k=0;
        while(k<n){
            
            if(isupper(str[k])){
                
                while(i<26 && arr1[i]==0){
                    
                    i++;
                }
                
                if(i<26){
                    
                    str[k]=(char)i+65;
                    
                    arr1[i]--;
                }
                
            }
            else{
                
                while(j<26 && arr2[j]==0){
                    
                    j++;
                }
                
                if(j<26){
                    
                    str[k]=(char)j+97;
                    
                    arr2[j]--;
                }
            }
            
            k++;
        }
        
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends
