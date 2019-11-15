class Solution {
public:
    double Power(double base, int exponent) {
        double ans = 1;
        bool flag = true;
        if(exponent < 0)
        {
            flag = false;
            exponent = -exponent;
        }
        while(exponent)
        {
            if(exponent&1)
            {
                ans *= base;
            }
            base *= base;
            exponent = exponent >> 1;
        }
        if(!flag)
        {
            ans = 1/ans;
        }
        return ans;
    }
};
