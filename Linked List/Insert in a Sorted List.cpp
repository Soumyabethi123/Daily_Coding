//{ Driver Code Starts
//

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
/*
structure of the node of the list is as
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
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        
        Node *temp=head;
        Node *prev=NULL;
        
        while(temp->next!=NULL && temp->data < data){
            
            prev=temp;
            temp=temp->next;
        }
        
        if(temp==head){
            
            Node *n=new Node(data);
            n->next=head;
            head=n;
        }
        else if(temp->next==NULL){
            
            if(temp->data < data){
                
                Node *n=new Node(data);
                temp->next=n;
                
            }
            else{
                
                Node *n=new Node(data);
                prev->next=n;
                n->next=temp;
            }
        }
        else{
            
            Node *n=new Node(data);
            prev->next=n;
            n->next=temp;
        }
        
        return head;
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
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends
