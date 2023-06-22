//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        
        int five=0,ten=0,twen=0;
        
        for(int i=0; i<N; i++){
            
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                
                if(five > 0){
                    
                    five--;
                    ten++;
                }
                else{
                    return 0;
                }
            }
            else{
                
                if(five > 0 && ten > 0){
                    ten--;
                    five--;
                    twen++;
                }
                else if(ten==0 && five > 2){
                    
                    five=five-3;
                    twen++;
                }
                else{
                    return 0;
                }
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
