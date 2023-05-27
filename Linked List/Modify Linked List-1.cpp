//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
    
    
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        int count=0;
        struct Node *curr=head;
        
        while(curr != NULL){
            
            count++;
            curr=curr->next;
        }
        
        vector<int>temp;
        
        curr=head;
        int count2=count/2;
        
        while(count2){
            
            temp.push_back(curr->data);
            curr=curr->next;
            
            count2--;
        }
        
        head=reverseList(head);
        
        curr=head;
        
        count2=count/2;
        int i=0;
        
        while(count2){
            
            curr->data=curr->data-temp[i];
            i++;
            curr=curr->next;
            count2--;
        }
        
        return head;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends
