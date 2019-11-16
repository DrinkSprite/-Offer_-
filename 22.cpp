/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty())
        {
            ans.push_back(nodeQueue.front()->val);
            if(nodeQueue.front()->left != NULL)
                nodeQueue.push(nodeQueue.front()->left);
            if(nodeQueue.front()->right != NULL)
                nodeQueue.push(nodeQueue.front()->right);
            nodeQueue.pop();
        }
        return ans;
    }
};
