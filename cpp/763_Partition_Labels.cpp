#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char,int> m;
        for (int i(0); i < S.size(); i++) {
            m[S[i]] = i;
        }
        int par(0), j(0);
        vector<int> res;
        for (int i(0); i < S.size();i++) {
            j = max(j,m[S[i]]);
            if (i == j) {
                res.push_back(i - par + 1);
                par = i+1;
            }
        }
        return res;
    }
    void print(vector<int> v) {
        for (auto i: v)
            cout << i << " ";
    }
};

int main()
{
    Solution sol;
    string S{"ababcbacadefegdehijhklij"};
    vector<int> res =  sol.partitionLabels(S);
    sol.print(res);
    return 0;
}