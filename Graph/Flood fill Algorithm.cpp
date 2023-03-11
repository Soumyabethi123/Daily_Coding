//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void fill(int x,int y,vector<vector<int>>& image,int newc,int n,int m,int c){
        
        if(x<n && x>=0 && y<m && y>=0){
            
            if(image[x][y]==c){
                
                image[x][y]=newc;
                
                fill(x,y+1,image,newc,n, m,c);
                fill(x,y-1,image,newc,n,m,c);
                fill(x-1,y,image,newc,n,m,c);
                fill(x+1,y,image,newc,n,m,c);
            }
        }
        else{
            
            return;
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int c=image[sr][sc];
        
        int n=image.size();
        
        int m=image[0].size();
        
        if(c==newColor){
            
            return image;
        }
        
        fill(sr,sc,image,newColor,n,m,c);
        
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
