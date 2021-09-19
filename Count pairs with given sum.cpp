class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        int count=0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=k)
                continue;
            else
            {
                if(freq.find(k-arr[i])!=freq.end())
                    count+=freq[k-arr[i]];
                freq[arr[i]]++;
            }
        }
        return count;
    }
};
