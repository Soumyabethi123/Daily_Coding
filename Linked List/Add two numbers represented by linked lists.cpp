//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node *prev=head;
        
        if(prev->next==NULL){
            
            return prev;
        }
        else{
            
            Node *curr=prev->next;
            prev->next=NULL;
            
            while(curr!=NULL){
                
                Node *temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            
            return prev;
        }
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        Node *curr1=reverseList(first);
        
        Node *curr2=reverseList(second);
        
        int c=0;
        
        Node *ans=NULL;
        Node *temp=NULL;
        
        while(curr1!=NULL && curr2!=NULL){
            
            int s = c + curr1->data + curr2->data;
            
            if(s>9){
                
                c=s/10;
                s=s%10;
                
            }
            else{
                c=0;
            }
            
          
            Node *n = new Node(s);
            
            if(ans==NULL){
                
                ans=n;
                temp=n;
            }
            else{
                
                temp->next=n;
                temp=n;
            }
            
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
        while(curr1 != NULL){
            
            int s = c + curr1->data ;
            
            if(s>9){
                
                c=s/10;
                s=s%10;
                
            }
            else{
                c=0;
            }
            
            Node *n = new Node(s);
            
            if(ans==NULL){
                
                ans=n;
                temp=n;
            }
            else{
                
                temp->next=n;
                temp=n;
            }
            
            curr1=curr1->next;
            
        }
        
        while(curr2 != NULL){
            
            int s = c + curr2->data ;
            
            if(s>9){
                
                c=s/10;
                s=s%10;
                
            }
            else{
                c=0;
            }
            
            Node *n = new Node(s);
            
            if(ans==NULL){
                
                ans=n;
                temp=n;
            }
            else{
                
                temp->next=n;
                temp=n;
            }
            
            curr2=curr2->next;
        }
        
        if(c>0){
            
            Node *n = new Node(c);
            
            if(ans==NULL){
                
                ans=n;
                temp=n;
            }
            else{
                
                temp->next=n;
                temp=n;
            }
        }
        
        Node *ans2=reverseList(ans);
        return ans2;
        
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
