class solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_set<int> pres;
        pres.insert(0);
        int prefix[n]={0};
        for(int i=0;i<n;i++)
        {
            if(i==0)
                prefix[i]=arr[i];
            else
            {
                prefix[i]=prefix[i-1]+arr[i];
                if(pres.find(prefix[i])!=pres.end())
                    return true;
            }
            pres.insert(prefix[i]);
        }
        return false;
    }
};
