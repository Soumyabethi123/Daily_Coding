//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &ch){
        // Code here
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans2(n,vector<int>(m,0));
        
        queue<pair<int,int>>q;
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(ch[i][j]=='W'){
                    
                    q.push({i,j});
                    vis[i][j]=1;
                    ans2[i][j]=0;
                }
            }
        }
        
        int ans=0;
        
        
        
        while(!q.empty()){
            
            int size=q.size();
            ans=ans+2;
            
            for(int i=0; i<size; i++){
            
               int r=q.front().first;
               int c=q.front().second;
            
               q.pop();
            
               if(r-1>=0 && r-1<n){
                   
                   if(vis[r-1][c]==0 && (ch[r-1][c]=='H' || ch[r-1][c]=='.' )){
                       
                       if(ch[r-1][c]=='H'){
                           
                           ans2[r-1][c]=ans;
                       }
                       
                       q.push({r-1,c});
                       vis[r-1][c]=1;
                   }
               }
               
               if(r+1>=0 && r+1<n){
                   
                   if(vis[r+1][c]==0 && (ch[r+1][c]=='H' || ch[r+1][c]=='.' )){
                       
                       if(ch[r+1][c]=='H'){
                            ans2[r+1][c]=ans;
                       }
                      
                       q.push({r+1,c});
                       vis[r+1][c]=1;
                   }
               }
               
               if(c-1>=0 && c-1<m){
                   
                   if(vis[r][c-1]==0 && ( ch[r][c-1]=='H' || ch[r][c-1]=='.' )){
                       
                       if(ch[r][c-1]=='H'){
                           ans2[r][c-1]=ans;
                       }
                       
                       q.push({r,c-1});
                       vis[r][c-1]=1;
                   }
               }
               
               if(c+1>=0 && c+1<m){
                   
                   if(vis[r][c+1]==0 && ( ch[r][c+1]=='H' || ch[r][c+1]=='.' )){
                       
                       if(ch[r][c+1]=='H'){
                           ans2[r][c+1]=ans;
                       }
                       
                       q.push({r,c+1});
                       vis[r][c+1]=1;
                   }
               }
            }
            
        }
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(ch[i][j]=='H' && ans2[i][j]==0){
                    ans2[i][j]=-1;
                }
            }
        }
        
        return ans2;
        
       
    }
};
