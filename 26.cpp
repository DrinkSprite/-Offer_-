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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        
        TreeNode* ans = NULL;
        TreeNode* pre = NULL;
        stack<TreeNode*> stkNode;
        
        stkNode.push(pRootOfTree);
        while(stkNode.top()->left != NULL)
        {
            stkNode.push(stkNode.top()->left);
        }
        
        while(!stkNode.empty())
        {
            if(ans == NULL)
            {
                ans = stkNode.top();
                pre = ans;
            }
            else
            {
                pre->right = stkNode.top();
                stkNode.top()->left = pre;
                pre = stkNode.top();
            }
            
            stkNode.pop();
            
            if(pre->right != NULL)
            {
                stkNode.push(pre->right);
                while(stkNode.top()->left != NULL)
                {
                    stkNode.push(stkNode.top()->left);
                }
            }
        }
        
        return ans;
    }
};
