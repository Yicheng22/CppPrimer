#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size < 2)
            return size; // 1 candy for 1 child
        // assign 1 to all positions in the vector
        vector<int> candies(size,1);
        
        // from left to right, increase 1 if right bigger than left
        for (int i(1); i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }
        // from right to left, if right bigger than left
        for (int i(size - 1); i > 0; i--) {
            if (ratings[i] < ratings[i-1])
                candies[i-1] = max(candies[i-1],candies[i] +1);
        }
        return accumulate(candies.begin(),candies.end(),0);
    }
};

int main()
{
    vector<int> ratings = {1,2,1,2,3,1,3,2,4,2,1,2,3,2,4};

    Solution sol;
    cout << sol.candy(ratings) << endl;
    return 0;
}