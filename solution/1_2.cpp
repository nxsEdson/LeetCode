class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        std::unordered_map<int, int> nums_all;
        
        for(int i = 0; i < nums.size(); i++)
            nums_all[nums[i]] = i;
        
        vector<int> output;
        for(int i = 0; i < nums.size(); i++)
            if (nums_all.find(target - nums[i]) != nums_all.end())
            {
                if (i == nums_all.at(target - nums[i]))
                    continue;
                
                output.push_back(i);
                output.push_back(nums_all.at(target - nums[i]));
                return output;
            }
        
        return output;
    }
};
