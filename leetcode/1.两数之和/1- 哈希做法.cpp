class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for(int i = 0; i<nums.size();i++){
            auto b = map.find(target - nums[i]);
            if(b!= map.end()){
                return {b->second, i};
            }
            map.insert(pair<int, int>(nums[i], i)); 
        }
        return {};
    }
};