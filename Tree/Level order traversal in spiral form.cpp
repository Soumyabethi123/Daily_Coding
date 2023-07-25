//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> findSpiral(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    queue<Node*>q;
	q.push(root);
	
	//for reverse level order traversal
	vector<int>ans;
	
	//To print nodes in new line using separator
	q.push(NULL);
	
	while(!q.empty()){
		
		Node*front=q.front();
		q.pop();
		
		if(front==NULL){
			
			ans.push_back(-1);
			
			if(!q.empty()){
			    
				q.push(NULL);
			}
			continue;
		}
		
		ans.push_back(front->data);
		
		if(front->left){
			q.push(front->left);
		}
		
		if(front->right){
			
			q.push(front->right);
		}
		
	}
	
	vector<int>ans2;
	
	int flag=0;
	int count=0;
	int i=0;
	
	while(i<ans.size()){
	    
	    if(ans[i]==-1){
	        
	        count++;
	    }
	    else{
	        ans2.push_back(ans[i]);
	    }
	    
	    if(count==2){
	        flag=1;
	        break;
	    }
	    
	    i++;
	}
	
	if(flag==0){
	    
	    return ans2;
	}
	else{
	    
	    i++;
	    
	    bool rev=0;
	    vector<int>temp;
	    
	    vector<int>::iterator it;
	    
	    while(i<ans.size()){
	        
	        if(ans[i]==-1 && rev==false){
	            
	            reverse(temp.begin(),temp.end());
	            rev=true;
	            
	            it=ans2.end();
	            
	            ans2.insert(it,temp.begin(),temp.end());
	            
	            temp.clear();
	        }
	        else if(ans[i]==-1 && rev==true){
	            
	            rev=false;
	            
	            it=ans2.end();
	            
	            ans2.insert(it,temp.begin(),temp.end());
	            
	            temp.clear();
	        }
	        else{
	            temp.push_back(ans[i]);
	        }
	        
	        i++;
	    }
	    
	    return ans2;
	}
}
