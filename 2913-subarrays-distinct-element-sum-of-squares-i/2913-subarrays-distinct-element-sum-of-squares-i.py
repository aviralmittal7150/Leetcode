class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0

        for i in range(n):
            st = set()

            for j in range(i, n):
                st.add(nums[j])
                distinct = len(st)
                ans += distinct * distinct

        return ans