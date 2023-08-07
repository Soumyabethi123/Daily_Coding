class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int>st1,st2;

        int n=heights.size();

        vector<int>next(n,0);
        vector<int>prev(n,0);

        st1.push(n);

        for(int i=n-1; i>=0; i--){

            while(st1.top()<n && heights[st1.top()] >= heights[i]){

                st1.pop();      
            }
            
            next[i]=st1.top();
            st1.push(i);
        }

        st2.push(-1);

        for(int i=0; i<n; i++){

            while(st2.top()>=0 && heights[st2.top()] >= heights[i]){

                st2.pop();
            }

            prev[i]=st2.top();
            st2.push(i);
        }

        int max1=0;

        for(int i=0; i<n; i++){

            max1=max(max1,heights[i]*(next[i]-prev[i]-1));
        }

        return max1;
    }
};
