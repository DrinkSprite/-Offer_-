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
    bool IsSametree(TreeNode* pRootA, TreeNode* pRootB)
    {
        if(pRootA == NULL && pRootB != NULL)
            return false;
        else if(pRootB == NULL)
            return true;
        
        if(pRootA->val != pRootB->val)
            return false;
        if(IsSametree(pRootA->left, pRootB->left) && IsSametree(pRootA->right, pRootB->right))
            return true;
        else
            return false;
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL)
        {
            return false;
        }
        
        if(IsSametree(pRoot1,pRoot2))
            return true;
        if(HasSubtree(pRoot1->left, pRoot2))
            return true;
        if(HasSubtree(pRoot1->right, pRoot2))
            return true;
        return false;
    }
};
