//Bruteforce
//Time complexity:- O(k)
//Space complexity:- O(1)
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(k==1)
            return min(arr1[0],arr2[0]);
        else if(k==m+n)
            return max(arr1[n-1],arr2[m-1]);
        int i=0;
        int j=0;
        int count=0;
        while(i<n && j<m)
        {
            if(arr1[i]<=arr2[j])
            {
                if(count==k-1)
                    return arr1[i];
                count++;
                i++;
            }
            else
            {
                if(count==k-1)
                    return arr2[j];
                count++;
                j++;
            }
        }
        return i==n?arr2[j+k-count-1]:arr1[i+k-count-1];
    }
};
