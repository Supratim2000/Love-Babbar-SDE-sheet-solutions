void swap(int* first,int* second)
{
    int temp=*first;
    *first=*second;
    *second=temp;
}
void rot(int arr[],int start,int end)
{
    int left=start;
    int right=end;
    while(left<right)
    {
        swap(&arr[left],&arr[right]);
        left++;
        right--;
    }
}

void rotate(int arr[], int n)
{
    rot(arr,0,n-1);
    rot(arr,1,n-1);
}
