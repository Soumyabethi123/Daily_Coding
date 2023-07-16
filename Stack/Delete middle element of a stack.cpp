//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    
    void rec(stack<int>&s, int ind){
        
        if(ind==1){
            
            s.pop();
            return;
        }
        
        int top=s.top();
        s.pop();
        
        rec(s,ind-1);
        
        s.push(top);
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        
        int ind=ceil((s.size()+1)/2);
        
        if(s.size()%2==0){
            
            ind++;
        }
        
        rec(s,ind);
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends
