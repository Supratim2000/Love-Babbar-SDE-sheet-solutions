#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
typedef long long ll;

bool detectCycle(vector<ll> graph[],vector<bool>& vis,ll src)
{
    queue<pair<ll,ll>> q;
    q.push({src,-1});
    vis[src]=true;
    while(!q.empty())
    {
        pair<ll,ll> curNode=q.front();
        ll curVal=curNode.first;
        ll curPar=curNode.second;
        q.pop();
        for(ll i=0;i<graph[curVal].size();i++)
        {
            ll adjNode=graph[curVal][i];
            if(!vis[adjNode])
            {
                vis[adjNode]=true;
                q.push({adjNode,curVal});
            }
            else
            {
                if(adjNode!=curPar)
                    return true;
            }
        }
    }
    return false;
}

bool isTree(vector<ll> graph[],ll n)
{
    vector<bool> vis;
    for(ll i=0;i<n;i++)
        vis.push_back(false);
    bool isCyclePresent=detectCycle(graph,vis,0);

    for(ll i=0;i<n;i++)
        if(!vis[i])
            return false;
    if(isCyclePresent)
        return false;
    return true;
}

int main()
{
    /*
    Sample input:-
    10 9
    0 2
    0 3
    3 1
    3 5
    2 4
    1 9
    5 6
    5 7
    5 8
    */

    fstream infile;
    infile.open("F:\\Placement related\\Coding Ninjas DSA\\Lecture-17(Graph-3)\\Graph\\input.txt",ios::in);
    if(!infile)
    {
        cout<<"Could not open file"<<endl;
        return 0;
    }

    ll n,e;
    infile>>n>>e;
    
    vector<ll> graph[n];

    for(ll i=0;i<e;i++)
    {
        ll u,v;
        infile>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<<isTree(graph,n)<<endl;
    return 0;
}
