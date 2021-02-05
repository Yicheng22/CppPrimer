#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit{0};
        for (int i{1}; i < prices.size(); i++) {
            int temp = prices[i] - prices[i-1];
            profit += temp > 0 ? temp:0 ;
        }
        return profit;
    }
};

int main() 
{
    Solution sol;
    vector<int> prices{1,3,2,5,2,4};
    cout << sol.maxProfit(prices) <<endl;
    return 0;
}
