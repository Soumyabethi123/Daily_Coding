//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        
        if( D==1 || D*9 <= S ){

            return "-1";
        }
        
        vector<int>temp;
        
        temp.push_back(1);
        D--;
        S--;
        
        while(D>1){
            
            temp.push_back(0);
            D--;
        }
        
        if(S<=9){
            
            temp.push_back(S);
        }
        else{
            
            temp.push_back(9);
            S=S-9;
            
            int i=temp.size()-2;
            
            while(i>=1 && S>0){
                
                if(S>=9){
                    
                    temp[i]=9;
                    S=S-9;
                }
                else{
                    
                    temp[i]+=S;
                    S=0;
                    break;
                }
                
                i--;
            }
            
            if(S>=9){
                
                return "-1";
            }
            else{
                temp[0]+=S;
            }
        
        }
        
        int j=temp.size()-1;
        
        while(j>=0 && temp[j]>=9){
            
            j--;
        }
        

        if(j<0){
                    
            return "-1";
        }
        else{
            
            if(j==temp.size()-1){
                
                temp[j]--;
                temp[j-1]++;
            }
            else{
                
                temp[j]++;
                temp[j+1]--;
                
            }
            
            string ans="";
                    
            for(int k=0; k<temp.size(); k++){
                        
                ans=ans+to_string(temp[k]);
            }
                    
            return ans;
        }
        
        /*for(int i=0; i<temp.size(); i++){
            
            cout<<temp[i];
        }
        
        return "-1";*/
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
