//{ Driver Code Starts
#include <bits/stdc++.h>
#define MAX 20
using namespace std;

struct Node
{
	int data;
	Node* right, *down;
	
	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};

void display(Node* head)
{
    Node* Rp;
	Node* Dp = head;
	while (Dp) {
		Rp = Dp;
		while (Rp) {
			cout << Rp->data << " ";
			if(Rp->right)cout << Rp->right->data << " ";
			else cout << "Null ";
			if(Rp->down)cout << Rp->down->data << " ";
			else cout << "Null ";
			Rp = Rp->right;
		}
		
		Dp = Dp->down;
	}
}
Node* constructLinkedMatrix(int mat[MAX][MAX], int n);

// driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mat[MAX][MAX];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];
        Node* head = constructLinkedMatrix(mat, n);
        if(!head)cout<<"-1";
	    else display(head);
	    cout<<"\n";
    }
	return 0;
}


// } Driver Code Ends


/*structure of the node of the linked list is as

struct Node
{
	int data;
	Node* right, *down;
	
	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};
*/
// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]
Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    // code here
    Node *head=NULL;
    Node *prev=NULL;
    Node *curr=NULL;
    
    for(int i=0; i<n; i++){
        
        for(int j=0; j<n; j++){
            
            if(head==NULL){
                
                Node *n=new Node(mat[i][j]);
                head=n;
                curr=n;
            }
            else if(prev==NULL){
                
                Node *n=new Node(mat[i][j]);
                curr->right=n;
                curr=n;
            }
            else if(j==0){
                
                Node *n=new Node(mat[i][j]);
                prev->down=n;
                curr=n;
                prev=prev->right;
            }
            else{
                
                Node *n=new Node(mat[i][j]);
                prev->down=n;
                curr->right=n;
                curr=n;
                prev=prev->right;
            }
        }
        
        if(i==0){
            
            prev=head;
            curr=head;
        }
        else{
            
            Node *temp=head;
            
            while(temp->down != NULL){
                
                temp=temp->down;
            }
            
            prev=temp;
        }
    }
    
    return head;
}
