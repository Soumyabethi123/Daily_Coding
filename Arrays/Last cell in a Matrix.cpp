//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        
        int i=0,j=0;
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int dir=3;
        
        //up -> 0 , dowm -> 1 , left -> 2, right -> 3
        
        int ans1,ans2;
        
        while(i>=0 && i<n && j<m && j>=0){
            
            ans1=i;
            ans2=j;
            
            if(matrix[i][j]==0){
                
                if(dir==0){
                    
                    i--;
                }
                else if(dir==1){
                    
                    i++;
                }
                else if(dir==2){
                    
                    j--;
                }
                else{
                    
                    j++;
                }
            }
            else{
                
                matrix[i][j]=0;
                
                if(dir==0){
                    
                    j++;
                    dir=3;
                }
                else if(dir==1){
                    
                    j--;
                    dir=2;
                }
                else if(dir==2){
                    
                    i--;
                    dir=0;
                }
                else{
                    
                    i++;
                    dir=1;
                }
            }
            
            
        }
        
        pair<int,int>p;
        p.first=ans1;
        p.second=ans2;
        
        return p;
        
    }

};
