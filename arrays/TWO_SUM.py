class Solution:
    def twoSum(self, nums, target):

        num_map = {}

        for i, num in enumerate(nums):

            complement = target - num

            if complement in num_map:
                return [num_map[complement], i]

            num_map[num] = i
"""
# Example usage:
solution = Solution()
nums = [2, 7, 11, 15]
target = 9
print(solution.twoSum(nums, target))  # Output: [0, 1]"""