#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0, starty = 0;
        int count = 1;
        int loop = n / 2;
        int mid = n / 2;
        int offset = 1;
        int i, j;
        while (loop --) {
            i = startx;
            j = starty;

            for (j; j < n - offset; j++) {
                res[i][j] = count++;
            }

            for (i; i < n - offset; i++) {
                res[i][j] = count++;
            }

            for (; j > starty; j--) {
                res[i][j] = count++;
            }

            for (; i > startx; i--) {
                res[i][j] = count++;
            }
            startx++;
            starty++;
            offset += 1;
        }
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};

void printvector(vector<vector<int>>& x) {
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x.size(); j++) {
            cout << x[i][j] << "\t";
        }
        cout << "\n";
    }
}
int main()
{
    //std::vector<int> x = { 1,4,4 };
    Solution solution;
    vector<vector<int>> res = solution.generateMatrix(4);
    //std::cout << res << endl;
    printvector(res);
    return 0;
}