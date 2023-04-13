#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    
	    ll n;
	    cin>>n;
	    
	    if(n==1 || n==2){
	        
	        cout<<0<<endl;
	    }
	    else if(n%2==0){
	        
	        cout<<((3*n)-6)/2<<endl;
	    }
	    else{
	        
	        cout<<((3*n)-5)/2<<endl;
	    }
	}
	return 0;
}
