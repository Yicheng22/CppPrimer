#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long num{0};
        int flag{1};
        if (x < 0) {
            flag = -1;
            x = abs(x);
        }
        while (x > 0) {
            num = num*10 + x%10;
            x /= 10;
        }
        num *= flag;
        if (num < -pow(2,31) || num> pow(2,31) -1)
            return 0;
        return num;
    }
};

int main()
{
    Solution sol;
    cout << sol.reverse(-123) <<endl;
    return 0;
}