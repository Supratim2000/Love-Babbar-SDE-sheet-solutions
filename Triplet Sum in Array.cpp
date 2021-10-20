class Solution{
    public:
    bool twoSum(int arr[],int l,int h,int target)
    {
        while(l<h)
        {
            if(arr[l]==target-arr[h])
                return true;
            arr[l]>target-arr[h]?h--:l++;
        }
        return false;
    }
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        for(int i=0;i<n-2;i++)
            if(twoSum(A,i+1,n-1,X-A[i]))
                return true;
        return false;
    }
};
