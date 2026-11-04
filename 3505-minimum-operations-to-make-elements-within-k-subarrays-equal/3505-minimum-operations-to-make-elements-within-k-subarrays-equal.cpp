class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
         int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        auto add = [&](int val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }

            // Balance the two halves
            while (low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= v;

                high.insert(v);
                sumHigh += v;
            }

            while (low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.begin());
                sumHigh -= v;

                low.insert(v);
                sumLow += v;
            }
        };

        auto remove = [&](int val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }

            // Balance again
            while (low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= v;

                high.insert(v);
                sumHigh += v;
            }

            while (low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.begin());
                sumHigh -= v;

                low.insert(v);
                sumLow += v;
            }
        };

        vector<long long> cost(n - x + 1);

        // Calculate cost of every window
        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                long long median = *low.rbegin();

                cost[i - x + 1] =
                    median * (long long)low.size() - sumLow
                    + sumHigh - median * (long long)high.size();
            }
        }

        // DP
        const long long INF = 4e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                // Skip current element
                dp[i][j] = dp[i - 1][j];

                // Select window ending at i-1
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};