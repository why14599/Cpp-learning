#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, minLen = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            // 当和满足条件时，尝试收缩左边界
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
        }
};

void printvector(vector<int>& x) {
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << "\t";
    }
}
int main()
{
    std::vector<int> x = { 1,4,4 };
    Solution solution;
    int res = solution.minSubArrayLen(4, x);
    std::cout << res<<endl;
    //printvector(x);
    return 0;
}