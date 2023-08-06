//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:

    set<int>leaf;
    
    void inorder(Node*root){
        
        if(root->left==NULL && root->right==NULL){
            
            leaf.insert(root->data);
            return;
        }
        
        if(root->left){
            
            inorder(root->left);
        }
        
        if(root->right){
            
            inorder(root->right);
        }
    }
    
    int getCount(Node *root, int k)
    {
        //code here
        vector<int>level;
        
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            
            Node*front = q.front();
            q.pop();
            
            if(front==NULL){
                
                level.push_back(-1);
                
                if(!q.empty()){
                    
                    q.push(NULL);
                    continue;
                }
            }
            else{
                
                level.push_back(front->data);
                
                if(front->left){
                    
                    q.push(front->left);
                }
                
                if(front->right){
                    
                    q.push(front->right);
                }
            }
        }
        
        inorder(root);
        
        int le=1;
        
        vector<int>cost;
        
        for(int i=0; i<level.size(); i++){
            
            if(level[i]==-1){
                
                le++;
            }
            else{
                
                if(leaf.find(level[i])!=leaf.end()){
                    
                    cost.push_back(le);
                }
            }
        }
        
        int count=0;
        
        for(int i=0; i<cost.size(); i++){
            
            if(cost[i] <= k){
                
                count++;
                k=k-cost[i];
            }
            else{
                
                break;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        int res = obj.getCount(root, k);
        cout << res << "\n";
    }
    return 0;
}

// } Driver Code Ends
