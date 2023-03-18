#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int find(int n){
    
    unordered_set<int>s;
    
    while(n%2==0){
        
        s.insert(2);
        n=n/2;
    }
    
    for(int i=3; i*i<=n; i=(i+2)){
        
        while(n%i==0){
            
            s.insert(i);
            n=n/i;
        }
    }
    
    if(n>2){
        
        s.insert(n);
    }
    
    return s.size();
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	map<int,int>m;
	
	for(int i=2; i<=100000; i++){
	    
	    m[i]=find(i);
	}
	
	map<int,vector<int>>m2;
	
	for(auto it : m){
	    
	    m2[it.second].push_back(it.first);
	}
	
	while(t--){
	    
	    int a,b,k;
	    cin>>a>>b>>k;
	    
	    int ans=0;
	    
	    for(auto it : m2[k]){
	        
	        if(it>=a && it<=b){
	            ans++;
	        }
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}
