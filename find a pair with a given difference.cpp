bool binSrc(int arr[],int n,int k)
{
    int l=0;
    int h=n-1;
    int m;
    while(l<=h)
    {
        m=l+(h-l)/2;
        if(arr[m]==k)
            return true;
        arr[m]<k?l=m+1:h=m-1;
    }
    return false;
}

bool findPair(int arr[], int size, int n){
    sort(arr,arr+size);
    for(int i=0;i<size;i++)
        if(binSrc(arr,size,arr[i]+n))
            return true;
    return false;
}
