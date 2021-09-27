#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        int left = 0;
        int right = matrix[0].size() - 1;
        int on = 0;
        int under = matrix.size() - 1;
        while (right >= left && under >= on) {
            for (int i = left; i <= right; ++i)ret.push_back(matrix[on][i]);
            ++on;
            if (on > under)break;
            for (int i = on; i <= under; ++i)ret.push_back(matrix[i][right]);
            --right;
            if (left > right)break;
            for (int i = right; i >= left; --i)ret.push_back(matrix[under][i]);
            --under;
            for (int i = under; i >= on; --i)ret.push_back(matrix[i][left]);
            ++left;
        }
        return ret;
    }
};

int main() {
    Solution a;
    vector<vector<int> > m = { {1},{2}, {3}, {4}, {5} };
    a.printMatrix(m);
    return 0;
}