//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        // Code here
        
        long int f1,f2;
        
        for(int i=0; i<matrix.size(); i++){
            
            for(int j=0; j<matrix[i].size(); j++){
                
                if(matrix[i][j]==0){
                    
                    f1=i;
                    f2=j;
                    break;
                }
            }
        }
        
        vector<long int>temp1;
        
        long int sum;
        
        for(int i=0; i<matrix.size(); i++){
            
            if(i != f1){
                
                sum=0;
                
                for(int j=0; j<matrix[i].size(); j++){
                
                    sum=sum+matrix[i][j];
                }
                
                temp1.push_back(sum);
            }
            
        }
        
        for(int j=0; j<matrix.size(); j++){
            
            if(j != f2){
                
            sum=0;
            
            for(int i=0; i<matrix[j].size(); i++){
                
                sum=sum+matrix[i][j];
            }
            temp1.push_back(sum);
            
            }
        }
        
        int n=matrix.size();
        
        if(f1!=f2){
            
            sum=0;
            for(int i=0; i<n; i++){
                
                for(int j=0; j<n; j++){
                    
                    if(i==j){
                        
                        sum=sum+matrix[i][j];
                    }
                }
            }
            
            temp1.push_back(sum);
            
        }
        
        if(f1+f2 != n-1){
            
            sum=0;
            
            for(int i=0; i<n; i++){
                
                for(int j=0; j<n; j++){
                    
                    if(i+j == n-1){
                        
                        sum=sum+matrix[i][j];
                    }
                }
            }
            
            temp1.push_back(sum);
        }
        
        int flag=0;
        
        long int ch=temp1[0];
        
        for(int i=1; i<temp1.size(); i++){
            
            if(temp1[i] != ch){
                
                flag=1;
                break;
            }
        }
        
        long long ans;
        if(flag==1){
            
            ans=-1;
        }
        else{
            
            long int sum1=0;
            
            for(int i=0; i<n; i++){
                
                if(i==f1){
                    
                for(int j=0; j<n; j++){
                    
                    sum1=sum1+matrix[i][j];
                }
                
                }
            }
            
            long int sum2=0;
            
            for(int i=0; i<n; i++){
                
                if(i==f2){
                    
                for(int j=0; j<n; j++){
                    
                    sum2=sum2+matrix[j][i];
                }
                
                }
            }
            
            int flag1=0,flag2=0;
            
            long int sum3=0;
            if(f1==f2){
                
                flag1=1;
                for(int i=0; i<n; i++){
                
                for(int j=0; j<n; j++){
                    
                    if(i==j){
                        
                        sum3=sum3+matrix[i][j];
                    }
                }
                }
            }
            
            long int sum4=0;
            
            if(f1+f2==n-1){
                
                flag2=1;
                for(int i=0; i<n; i++){
                
                for(int j=0; j<n; j++){
                    
                    if(i+j == n-1){
                        
                        sum4=sum4+matrix[i][j];
                    }
                }
            }
            }
            
            
            int flag4=0;
            
            if(flag1==1 && flag2==1){
                
                if(sum1==sum2 && sum2==sum3 && sum3==sum4){
                    
                    flag4=1;
                }
            }
            else if(flag1==1){
                
                if(sum1==sum2 && sum2==sum3){
                    
                    flag4=1;
                }
            }
            else if(flag2==1){
                
                if(sum1==sum2 && sum2==sum4){
                    
                    flag4=1;
                }
            }
            else{
                
                if(sum1 == sum2){
                
                   flag4=1;
                }
            }
            
            if(flag4==0){
                
                ans=-1;
            }
            else{
                
                ans=ch-sum1;
                
                if(ans<=0){
                    
                    ans=-1;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
