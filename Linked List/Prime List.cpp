//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:

    int check(int n){
        
        if(n==1){
            return 0;
        }
        else if(n==2){
            return 1;
        }
        else{
            
            for(int i=2; i<=sqrt(n); i++){
                
                if(n%i==0){
                    return 0;
                }
            }
            
            return 1;
        }
    }
    
    
    Node *primeList(Node *head){
        
        Node *curr=head;
        
        while(curr!=NULL){
            
            if(curr->val==1){
                
                curr->val=2;
            }
            else{
                
                int data=curr->val;
                
                if(check(data)==0){
                    
                    int x=data-1;
                    int y=data+1;
                    
                    while(check(x)==0 && check(y)==0){
                        
                        x--;
                        y++;
                    }
                    
                    if(check(x)){
                        
                        curr->val=x;
                    }
                    else{
                        curr->val=y;
                    }
                }
            }
            
            curr=curr->next;
        }
        
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
