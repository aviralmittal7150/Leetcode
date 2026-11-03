class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        return maxVal * nums.size() - sum;
    }
};