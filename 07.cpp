class Solution {
public:
    int Fibonacci(int n) {
        if(n < 2)
            return n;
        int ans = 1;
        int tmp = 0;
        int pre = 0;
        for(int i = 1;i < n;i++)
        {
            tmp = pre;
            pre = ans;
            ans += tmp;
        }
        
        return ans;
    }
};
