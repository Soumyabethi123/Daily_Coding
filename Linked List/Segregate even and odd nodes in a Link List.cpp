//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        
        Node *even;
        Node *odd;
        Node *curre;
        Node *curro;
        Node *curr;
        
        if(head->data%2==0){
            
            even=head;
            curre=head;
            
            Node *temp=head->next;
            
            while(temp!=NULL && temp->data%2==0){
                
                curre=temp;
                temp=temp->next;
            }
            
            if(temp==NULL){
                return head;
            }
            
            curr=temp->next;
            odd=temp;
            curro=odd;
            
            odd->next=NULL;
            curre->next=NULL;
        }
        else{
            
            odd=head;
            curro=head;
            
            Node *temp=head->next;
            
            while(temp!=NULL && temp->data%2==1){
                
                curro=temp;
                temp=temp->next;
            }
            if(temp==NULL){
                
                return head;
            }
            
            curr=temp->next;
            even=temp;
            curre=temp;
            
            even->next=NULL;
            curro->next=NULL;
            
        }
        
        //return curre;
        
        while(curr!=NULL){
            
            Node *next=curr->next;
                
                if(curr->data%2==0){
                    
                    curre->next=curr;
                    curr->next=NULL;
                    curre=curre->next;
                }
                else{
                    
                    curro->next=curr;
                    curr->next=NULL;
                    curro=curro->next;
                    
                }
            
            
            curr=next;
        }
        
        curre->next=odd;
        
        return even;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends
