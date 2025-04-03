from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}
        for i, num in enumerate(nums):

            rem = target - num
            if rem in num_map:
                return [num_map[rem], i]
            num_map[num] = i
        return []

