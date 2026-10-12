class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
        
    }
};