#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = sqrt(c);
        while(left <= right){
            long temp = left*left + right*right;
            if(temp > c){
                right--;
            }else if(temp < c){
                left ++;
            }else{
                cout << left << "x" << left
                    << " + " <<  right << "x" << right 
                    << " = " << c;
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    sol.judgeSquareSum(13);
    return 0;
}