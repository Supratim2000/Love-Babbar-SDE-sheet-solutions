class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        vector<pair<int,int>> temp;
        map<int,int> levelNode;
        if(!root)
            return ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            pair<Node*,int> curNode=q.front();
            temp.push_back({curNode.second,curNode.first->data});
            q.pop();
            if(curNode.first->left)
                q.push({curNode.first->left,curNode.second-1});
            if(curNode.first->right)
                q.push({curNode.first->right,curNode.second+1});
        }
        for(int i=temp.size()-1;i>=0;i--)
            levelNode.insert({temp[i].first,temp[i].second});
        for(auto it=levelNode.begin();it!=levelNode.end();it++)
            ans.push_back(it->second);
        return ans;
    }
};
