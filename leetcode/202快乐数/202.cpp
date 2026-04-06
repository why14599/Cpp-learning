#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int sum = getSum(n);
        unordered_set<int> nums;
        while (true) {
            if (sum == 1) {
                return true;
            }
            if (nums.find(sum) != nums.end()) {
                return false;
            }
            else nums.insert(sum);
            n = sum;
        }
    }
};

int main() {
    Solution A;
    cout << A.isHappy(19) << endl;
    return 0;
}