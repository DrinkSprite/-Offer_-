class Solution {
public:
    int jumpFloor(int number) {
        if(number < 3)
            return number;
        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};
