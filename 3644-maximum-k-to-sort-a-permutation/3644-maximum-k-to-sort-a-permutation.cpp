class Solution {
public:
    int sortPermutation(vector<int>& nums) {
       int n = nums.size();
        int ans = -1;  // all bits set (two's complement)
        bool any = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans &= nums[i];
                any = true;
            }
        }
        return any ? ans : 0; 
    }
};