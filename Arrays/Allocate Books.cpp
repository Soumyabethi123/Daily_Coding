
int find(vector<int>& arr, int n, int m,int mid){

    int count=1;
    int sum=0;

    for(int i=0; i<n; i++){

        if(sum+arr[i] <= mid){

            sum=sum+arr[i];
        }
        else{
            count++;

            if(count > m || mid < arr[i]){
                return 0;
            }
            sum=arr[i];
        }
    }

   return 1;
}


int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.

    int l=0;
    int h=0;

    for(int i=0; i<n; i++){

        h=h+arr[i];
    }

    int ans=-1;
    while(l<=h){

        int mid=(l+h)/2;

        if(find(arr,n,m,mid)){

            ans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }

    if(m>n){
        return -1;
    }

    return ans;
}
