//Method 1(Using QUEUE and reversing after level interval)
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


//Method 2(Using DEQUEUE) (Most optimised)
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> ans;
        if(!root)
            return ans;
    	deque<Node*> dq;
    	int level=1;
    	dq.push_front(root);
    	while(!dq.empty())
    	{
    	    int n=dq.size();
    	    for(int i=0;i<n;i++)
    	    {
    	        Node* curNode=nullptr;
    	        if(level&1)
    	        {
    	            curNode=dq.back();
    	            ans.push_back(curNode->data);
    	            dq.pop_back();
    	            if(curNode->left)
    	                dq.push_front(curNode->left);
    	            if(curNode->right)
    	                dq.push_front(curNode->right);
    	        }
    	        else
    	        {
    	            curNode=dq.front();
    	            ans.push_back(curNode->data);
    	            dq.pop_front();
    	            if(curNode->right)
    	                dq.push_back(curNode->right);
    	            if(curNode->left)
    	                dq.push_back(curNode->left);
    	        }
    	    }
    	    level++;
    	}
    	return ans;
    }
};
