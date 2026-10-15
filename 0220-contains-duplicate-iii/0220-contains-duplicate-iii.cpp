
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (indexDiff <= 0 || valueDiff < 0)
            return false;

        multiset<long long> window;

        for (int i = 0; i < nums.size(); i++) {
            long long x = nums[i];

            // Find the smallest element >= x - valueDiff
            auto it = window.lower_bound(x - valueDiff);

            // Check whether a valid value exists
            if (it != window.end() && *it <= x + valueDiff)
                return true;

            window.insert(x);

            // Maintain at most indexDiff previous elements
            if (window.size() > indexDiff)
                window.erase(window.find(nums[i - indexDiff]));
        }

        return false;
    }
};
