class Solution{
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    int count=0;
	    sort(arr,arr+n);
	    for(int i=0;i<=n-3;i++)
	    {
	        int l=i+1;
	        int h=n-1;
	        while(l<h)
	        {
	            if(arr[i]+arr[l]<sum-arr[h])
	            {
	                count+=h-l;
	                l++;
	            }
	            else
	                h--;
	        }
	    }
	    return count;
	}
};
