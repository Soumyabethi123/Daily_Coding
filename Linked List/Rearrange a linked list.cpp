//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Node structure

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

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
       
       if(head->next==NULL){
           
           return;
       }
       else{
           
           Node *oddh=head;
           Node *evenh=head->next;
           
           Node *odd=head;
           Node *even=head->next;
           
           Node *curr=even->next;
           
           odd->next=NULL;
           even->next=NULL;
           
           while(curr != NULL){
               
               Node *next=curr->next;
               
               odd->next=curr;
               odd=curr;
               odd->next=NULL;
               
               curr=next;
               
               if(curr != NULL){
                   
                   Node *next2=curr->next;
                   
                   even->next=curr;
                   even=curr;
                   even->next=NULL;
                   
                   curr=next2;
                   
               }
           }
           
           odd->next=evenh;
           
           head=oddh;
       }
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends
