//Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		std::map<int, int> numsMap;

        for (int i = 0; i < nums.size(); i++)
        {
            register int val = nums[i];
            if(numsMap.count(val) > 0) // exist
            { 
                if((i - numsMap[val]) <= k ) return true;
            }
            numsMap[val] = i;
        }
        return false;
    }
};
