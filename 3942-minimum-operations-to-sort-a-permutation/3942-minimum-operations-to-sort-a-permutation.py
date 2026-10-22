from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        k = nums[0]
        best = float('inf')

        # Case A: rotation of sorted array
        if all(nums[i] == (k + i) % n for i in range(n)):
            if k == 0:
                best = 0
            else:
                best = min(best, n - k, k + 2)

        # Case B: rotation of reversed sorted array
        if all(nums[i] == (k - i) % n for i in range(n)):
            best = min(best, 1 + (n - k - 1) % n, k + 2)

        return -1 if best == float('inf') else best