
int find(vector<int> &stalls, int k,int mid){

    int count=1;

    int i=1;
    int s=stalls[0];

    while(i<stalls.size()){

        if(s+mid <= stalls[i]){

            count++;
            if(count == k){

                return 1;
            }

            s=stalls[i];
        }

        i++;
    }

    if(count == k){

        return 1;
    }

    return 0;

}


int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.

    int l=0;

    sort(stalls.begin(),stalls.end());

    int h=stalls[stalls.size()-1]-stalls[0];

    int ans=-1;

    while(l<=h){

        int mid=(l+h)/2;

        if(find(stalls,k,mid)){

            ans=mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }

    }

    return ans;
}
