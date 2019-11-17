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
private:
    vector<vector<int> > ans;
    vector<int> listPath;
    int sum;
    int x;
    
    void findX(TreeNode* root)
    {
        sum += root->val;
        listPath.push_back(root->val);
        
        if(NULL != root->left)
            findX(root->left);
        if(NULL != root->right)
            findX(root->right);
        
        if(NULL == root->left && NULL == root->right)
        {
            if(sum == x)
            {
                ans.push_back(listPath);
            }
        }
        
        listPath.pop_back();
        sum -= root->val;
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        ans.clear();
        if(NULL == root)
            return ans;
        
        listPath.clear();
        sum = 0;
        x = expectNumber;
        
        findX(root);
        
        if(ans.size() == 0)
            return ans;
        
        for(int i = 0;i < ans.size() - 1;i++)
        {
            for(int j = 1;j < ans.size() - i;j++)
            {
                if(ans[j].size() > ans[j - 1].size())
                {
                    ans[j - 1].swap(ans[j]);
                }
            }
        }
        return ans;
    }
};
