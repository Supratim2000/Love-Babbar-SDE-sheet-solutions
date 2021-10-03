#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int optimisedSearch(vector<int>& vec,int key,int k)
{
    int n=vec.size();
    int i=0;
    int diff;
    while(i<=n-1)
    {
        if(vec[i]==key)
            return i;
        diff=abs(vec[i]-key);
        int x=(diff+k-1)/k;
        i+=x;
    }
    return INT_MIN;
}

int main()
{
    int n;
    int key;
    int k;
    int element;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> vec;
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>element;
        vec.push_back(element);
    }
    cout<<"Enter key: ";
    cin>>key;
    cout<<"Enter difference between adjacent elements: ";
    cin>>k;
    int ans=optimisedSearch(vec,key,k);
    if(ans==INT_MIN)
        cout<<"Element not present in array"<<endl;
    else
        cout<<"Element present at: "<<ans<<" index"<<endl;
    
    return 0;
}
