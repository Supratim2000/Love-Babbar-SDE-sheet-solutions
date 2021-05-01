class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    
	    int cur_col=0;
	    for(int i=0;i<n && cur_col<m;i++)
	    {
	        if(arr[i][cur_col]==1)
	            return i;
	        if(i==n-1) {
	            i=0;
	            cur_col++;
	        }
	    }
	    return -1;
	}
};
