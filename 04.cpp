/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        
        if(0 == pre.size() || 0 == vin.size())
        {
            return NULL;
        }
        
        TreeNode* ans = new TreeNode(pre[0]);
        unsigned int indx = 0;
        for(int i = 0;i < vin.size(); i++)
        {
            if(pre[0] == vin[i])
            {
                indx = i;
                break;
            }
        }
        
        vector<int> tmpPre,tmpVin;
        vector<int>::iterator tmpIt;
        if(0 != indx)
        {
            tmpIt = pre.begin();
            tmpPre.assign(tmpIt + 1,tmpIt + indx + 1);
            tmpIt = vin.begin();
            tmpVin.assign(tmpIt,tmpIt + indx);
        }
        ans->left = reConstructBinaryTree(tmpPre,tmpVin);
        
        tmpPre.clear();
        tmpVin.clear();
        if(0 != vin.size() - indx -1)
        {
            tmpIt = pre.begin();
            tmpPre.assign(tmpIt + indx + 1,tmpIt + pre.size());
            tmpIt = vin.begin();
            tmpVin.assign(tmpIt + indx + 1,tmpIt + vin.size());
        }
        ans->right = reConstructBinaryTree(tmpPre,tmpVin);
        
        return ans;
    }
};
