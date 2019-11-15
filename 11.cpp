class Solution {
public:
     int  NumberOf1(int n) {
         int cnt = 0;
         while(0 != n)
         {
             cnt++;
             n = n&(n-1);
         }
         return cnt;
     }
};
