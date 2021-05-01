//User function Template for C++

//Method 1
string reverseWord(string str){
    int n=str.size(); 
    for(int i=0;i<n/2;i++) {
        char temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
    return str;
}

//Method 2
string reverseWord(string str){
    int n=str.size(); 
    int l=0;
    int h=n-1;
    while(l<h)
        swap(str[l++],str[h--]);
    return str;
}
