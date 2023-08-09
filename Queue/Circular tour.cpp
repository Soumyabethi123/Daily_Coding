//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       
       int st=0,i=0;
       int bal=0;
       int def=0;
       
       while(i<n){
           
           bal=bal+(p[i].petrol-p[i].distance);
           
           if(bal < 0){
               
               def=def+bal;
               st=i+1;
               bal=0;
           }
           
           i++;
       }
       
       if(def+bal < 0){
           
           return -1;
       }
       
       else{
           
           return st;
       }
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends
