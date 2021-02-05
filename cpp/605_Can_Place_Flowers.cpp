#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, count = 0;
        while (i < flowerbed.size()) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i++] = 1;
                count++;
            }
             if(count>=n)
                return true;
            i++;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> flowerbed = {1,0,0,0,0,1};
    if (sol.canPlaceFlowers(flowerbed,1)){
        cout << "True" <<endl;
    } 

    if (sol.canPlaceFlowers(flowerbed,2)){
        cout << "True" <<endl;
    }
    return 0;
}