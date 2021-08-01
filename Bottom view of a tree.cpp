class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int,int> levelNode;
        if(!root)
            return ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            pair<Node*,int> curNode=q.front();
            levelNode[curNode.second]=curNode.first->data;
            q.pop();
            if(curNode.first->left)
                q.push({curNode.first->left,curNode.second-1});
            if(curNode.first->right)
                q.push({curNode.first->right,curNode.second+1});
        }
        for(auto it=levelNode.begin();it!=levelNode.end();it++)
            ans.push_back(it->second);
        return ans;
    }
};
