class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> x(array);
        for(int i = 0,j = 0;i < x.size();i++)
        {
            if(x[i]%2 == 1)
            {
                array[j] = x[i];
                j++;
            }
        }
        
        for(int i = x.size()-1,j = x.size()-1;i >=0 ;i--)
        {
            if(x[i]%2 == 0)
            {
                array[j] = x[i];
                j--;
            }
        }
    }
};
