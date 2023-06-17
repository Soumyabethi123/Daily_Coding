//User function Template for C++
// Helper class Solution to implement 
// insert() and findFrequency()
class Solution{
    public:
    // Function to insert element into the queue
    void insert(queue<int> &q, int k){
        // Your code here
        q.push(k);
    }
    
    // Function to find frequency of an element
    // return the frequency of k
    int findFrequency(queue<int> &q, int k){
        // Your code here
        
        int count=0;
        
        int n=q.size();
        
        for(int i=0; i<n; i++){
            
            int temp=q.front();
            if(temp==k){
                
                count++;
            }
            
            q.pop();
            q.push(temp);
        }
        
        return count;
    }
    
};
