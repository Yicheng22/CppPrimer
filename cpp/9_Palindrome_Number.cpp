#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int tmp{x};
        if (x < 0)
            return false;
        int res{0};
        while (x > 0) {
            res = res*10 +  x%10;
            x /= 10;
        }
        
        return res == tmp;
    }
};


int main()
{
    Solution sol;
    int x{1122332211};
    if (sol.isPalindrome(x))
        cout << "Palindrome number" << endl;
    return 0;
}