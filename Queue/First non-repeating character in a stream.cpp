class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		    string ans="";
		    
		    map<char,int>mp;
		    queue<char>q;
		    
		    ans.push_back(A[0]);
		    q.push(A[0]);
		    mp[A[0]]++;
		    
		    for(int i=1; i<A.size(); i++){
		        
		        mp[A[i]]++;
		        
		        if(mp[A[i]]==1){
		            
		            q.push(A[i]);
		        }
		        
		        while(!q.empty()){
		            
		            if(mp[q.front()] > 1){
		                
		                q.pop();
		            }
		            else{
		                break;
		            }
		        }
		        
		        if(q.empty()){
		            
		            ans.push_back('#');
		        }
		        else{
		            ans.push_back(q.front());
		        }
		        
		    }
		    
		    return ans;
		}

};
