class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> nums;
        vector<int> fact(n + 1, 1);

        // Calculate factorials
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            nums.push_back(i);
        }

        k--; // Convert k to zero-based indexing

        while (n > 0) {
            int index = k / fact[n - 1];

            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);

            k %= fact[n - 1];
            n--;
        }

        return ans;
    }
};
;