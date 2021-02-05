#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
            });

        vector<vector<int>> queue;
        for (int i = 0; i < people.size(); i++) {
           queue.insert(queue.begin() + people[i][1], people[i]);
        }
        return queue;
    }

    void print2dVector(vector<vector<int>>& people) {
        for (int i{0};i< people.size(); i++) {
            cout << "[" << people[i][0] << "," <<people[i][1] << "]," ;
        }
        cout << endl;
    }
};

int main()
{   
    Solution sol;
    vector<vector<int>> people{{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}}};
    vector<vector<int>> queue = sol.reconstructQueue(people);
    sol.print2dVector(queue);
    return 0;
}