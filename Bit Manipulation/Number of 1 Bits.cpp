//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int decToBinary(int n)
   {
    // array to store binary number
    
    int count=0;
    
    while (n > 0) {
 
        // storing remainder in binary array
        int temp = n % 2;
        n = n / 2;
        
        if(temp==1){
            
            count++;
        }
    }
    
    return count;
    
   }
 

    int setBits(int N) {
        // Write Your Code here
        
        return decToBinary(N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends
