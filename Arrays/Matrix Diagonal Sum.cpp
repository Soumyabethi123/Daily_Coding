class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
       int sum=0;
       for(int i=0; i<mat.size(); i++){

           for(int j=0; j<mat[i].size(); j++){

               if(i==j){

                   sum=sum+mat[i][j];
               }
           }
       }

       cout<<sum<<endl;

       int r=0,c=mat[0].size()-1;
       int n=mat.size();
      
       while(c>=0){

           sum=sum+mat[r][c];

           r++;
           c--;
       }

        cout<<sum<<endl;

       if(n%2==1){
             sum=sum-mat[n/2][n/2];
       }
       

       return sum;
    }
};
