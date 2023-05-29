//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dict, string Patt) {
        // code here
        
        int i=0;
        
        vector<string>ans;
        
        for(int j=0; j<N; j++){
            
            string temp=Dict[j];
            int flag=0;
            
            for(int k=0; k<temp.size(); k++){
                
                if(i==Patt.size()){
                    
                    flag=1;
                    break;
                }
                
                if(isupper(temp[k])){
                    

                    if(temp[k]==Patt[i]){
                        
                        //cout<<temp[k]<<" "<<Patt[i]<<endl;
                        i++;
                    }
                    else{
                        
                        break;
                    }
                }
            }
            
            if(i==Patt.size()){
                
                flag=1;
            }
            
            if(flag==1){
                
                //cout<<temp[0]<<endl;
                ans.push_back(temp);
            }
            
            i=0;
        }
        
        if(ans.size()==0){
            
            ans.push_back("-1");
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
