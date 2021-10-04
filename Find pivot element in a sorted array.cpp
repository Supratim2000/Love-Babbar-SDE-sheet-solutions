int findPiv(int arr[], int l, int h)
{
    int pivIndx=-1;
    while(l<=h)
    {
      int mid=l+(h-l)/2;
      if(arr[mid]>arr[0])
      {
        pivIndx=mid;
        l=mid+1;
      }
      else
        h=mid-1;
      }
        return pivIndx;
  }
