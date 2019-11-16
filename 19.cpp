class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        
        vector<int> ans;
        
        if(matrix.size() == 0)
            return ans;
        if(matrix[0].size() == 0)
            return ans;
        
        int xs = 0;
        int ys = 0;
        int xe = matrix.size() - 1;
        int ye = matrix[0].size() - 1;
        
        while(xs<=xe && ys<=ye)
        {
            if(xs == xe && ys == ye)
            {
                ans.push_back(matrix[xs][ys]);
                break;
            }
            if(xs != xe && ys == ye)
            {
                for(int i = xs;i <= xe;i++)
                {
                    ans.push_back(matrix[i][ys]);
                }
                break;
            }
            if(xs == xe && ys != ye)
            {
                for(int i = ys;i <= ye;i++)
                {
                    ans.push_back(matrix[xs][i]);
                }
                break;
            }
            
            for(int i = ys;i < ye;i++)
            {
                ans.push_back(matrix[xs][i]);
            }
            for(int i = xs;i < xe;i++)
            {
                ans.push_back(matrix[i][ye]);
            }
            for(int i = ye;i > ys;i--)
            {
                ans.push_back(matrix[xe][i]);
            }
            for(int i = xe;i > xs;i--)
            {
                ans.push_back(matrix[i][ys]);
            }
            
            xs++;
            xe--;
            ys++;
            ye--;
        }
        return ans;
    }
};
