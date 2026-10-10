
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<int> diff(n);

        long long total = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        if (total <= k) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid)
                    need += d - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long ans = 0;
        long long used = 0;

        for (int d : diff) {
            int reduced = min(d, low);
            ans += 1LL * reduced * reduced;
            used += d - reduced;
        }

        long long remaining = k - used;

        // Reduce remaining differences from low to low - 1.
        // Each such reduction saves low^2 - (low - 1)^2.
        ans -= remaining * (2LL * low - 1);

        return ans;
    }
};

