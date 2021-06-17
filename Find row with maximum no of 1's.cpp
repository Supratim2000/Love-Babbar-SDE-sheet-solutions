class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans=-1;
	    int i=0,j=m-1;
	    while(i<=n-1 && j>=0)
	    {
	        while(arr[i][j]==1 && j>=0)
	        {
	            ans=i;
	            j--;
	        }
	        if(j==-1)
	            return i;
	        i++;
	    }
	    return ans;
	}
};
