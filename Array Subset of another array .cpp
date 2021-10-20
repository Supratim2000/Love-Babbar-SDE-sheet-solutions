//Method 1
bool binSrc(int arr[],int n,int key)
{
    int l=0;
    int h=n-1;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        if(arr[m]==key)
            return true;
        else if(arr[m]>key)
            h=m-1;
        else
            l=m+1;
    }
    return false;
}

string isSubset(int a1[], int a2[], int n, int m) {
    sort(a1,a1+n);
    sort(a2,a2+m);
    for(int i=0;i<m;i++)
    {
        if(!binSrc(a1,n,a2[i]))
            return "No";
    }
    return "Yes";
}

//Method 2
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_set<int> hash;
    for(int i=0;i<n;i++)
        hash.insert(a1[i]);
    for(int i=0;i<m;i++)
        if(hash.find(a2[i])==hash.end())
            return "No";
    return "Yes";
}
