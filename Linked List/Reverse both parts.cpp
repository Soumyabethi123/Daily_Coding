//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:

    Node* reverseList(Node *head)
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
   
    Node *reverse(Node *head, int k)
    {
        // code here
        
        Node *head1=head;
        Node *curr=head;
        
        while(k>1){
            
            curr=curr->next;
            k--;
        }
        
        Node *head2=curr->next;
        
        curr->next=NULL;
        
        Node *ans=reverseList(head1);
        
        Node *curr2=ans;
        while(curr2->next != NULL){
            
            curr2=curr2->next;
        }
        
        curr2->next=reverseList(head2);
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends
