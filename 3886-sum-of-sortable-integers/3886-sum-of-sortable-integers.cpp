class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool possible = true;
            int prev = INT_MIN;

            for (int start = 0; start < n; start += k) {
                int descents = 0;
                int descentIndex = -1;

                // Find where the block decreases.
                for (int j = 1; j < k; j++) {
                    if (nums[start + j] < nums[start + j - 1]) {
                        descents++;
                        descentIndex = j;
                    }
                }

                // A sorted cyclic rotation has at most
                // one descent.
                if (descents > 1) {
                    possible = false;
                    break;
                }

                int pivot = (descentIndex == -1) ? 0 : descentIndex;

                // Check the rotated block without creating a vector.
                int first = nums[start + pivot];
                int last = nums[start + (pivot + k - 1) % k];

                if (first < prev) {
                    possible = false;
                    break;
                }

                // Verify the rotated sequence is non-decreasing.
                for (int j = 1; j < k; j++) {
                    int curr = nums[start + (pivot + j) % k];
                    int before = nums[start + (pivot + j - 1) % k];

                    if (curr < before) {
                        possible = false;
                        break;
                    }
                }

                if (!possible) break;
                prev = last;
            }

            if (possible) ans += k;
        }

        return ans;
    }
};