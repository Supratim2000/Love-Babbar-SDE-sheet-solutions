vector <int> zigZagTraversal(Node* root)
{
    bool t=true;
	vector<int> ans;
	vector<int> level;
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
	    int n=q.size();
	    for(int i=0;i<n;i++)
	    {
	        Node* curNode=q.front();
	        q.pop();
	        level.push_back(curNode->data);
	        if(curNode->left)
	            q.push(curNode->left);
	        if(curNode->right)
	            q.push(curNode->right);
	    }
	    
	    if(t)
	    {
	        for(int i=0;i<level.size();i++)
	            ans.push_back(level.at(i));
	    }
	    else
	    {
	        for(int i=level.size()-1;i>=0;i--)
	            ans.push_back(level.at(i));
	    }
	    t=!t;
	    level.clear();
	}
	return ans;
}
