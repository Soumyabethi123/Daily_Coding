//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int n){
    //complete the function here
    
    //all a --> n!/n!=1

    //1b and remaining a --> n!/(n-1)!=n

    //1c and remaining a --> n!/(n-1)!=n

    //2c and remaining a --> n!/2!(n-2)!=n*(n-1)/2;

    //1b and 1c and remaining a --> n!/(n-2)!=n*(n-1)

    //2c and 1b and remaining a --> n!/2!*(n-3)!=n*(n-1)*(n-2)/2;

    return 1+n+n+n*(n-1)/2+n*(n-1)+n*(n-1)*(n-2)/2;
}
