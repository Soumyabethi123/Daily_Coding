// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        
        int ans=0;
        int n=s.size();
        
        if(n==1){
            
            return 1;
        }
        
        string temp="";
        
        int i=0;
        
        while(s.size() > 0){
            
            temp.push_back(s[i]);
            
            s.erase(i,1);
            
            if(temp.size() <= s.size()){
                
                int flag=0;
                for(int j=0; j<temp.size(); j++){
                    
                    if(temp[j] != s[j]){
                        
                        flag=1;
                        break;
                    }
                }
                
                if(flag==0){
                    
                    if(ans < temp.size()){
                        
                        ans=temp.size();
                    }
                }
            }
            
            
        }
        
        return n-(ans)+1;
    }
};
