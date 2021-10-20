    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        for(int i=0;i<n-2;i++)
        {
            int cur=A[i];
            int l=i+1;
            int h=n-1;
            while(l<h)
            {
                if(cur+A[l]+A[h]==X)
                    return true;
                else if(cur+A[l]+A[h]<X)
                    l++;
                else
                    h--;
            }
        }
        return false;
    }
};
