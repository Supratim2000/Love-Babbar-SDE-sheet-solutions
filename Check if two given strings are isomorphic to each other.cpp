#include<unordered_map>
#include<unordered_set>
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.size()!=str2.size())
            return false;
        int n=str1.size();
        unordered_map<char,char> mp;
        unordered_set<char> prevFound;
        for(int i=0;i<n;i++)
        {
            if(mp.find(str1[i])==mp.end())
            {
                if(prevFound.find(str2[i])!=prevFound.end())
                    return false;
                else
                {
                    mp[str1[i]]=str2[i];
                    prevFound.insert(str2[i]);
                }
            }
            else if(mp[str1[i]]!=str2[i])
                    return false;
        }
        return true;
    }
};
