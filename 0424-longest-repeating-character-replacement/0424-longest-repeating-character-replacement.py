class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        max_length = 0
        max_freq = 0
        left = 0


        for right in range(len(s)):
            char_right = s[right]
            count[char_right] = count.get(char_right,0) + 1


            max_freq = max(max_freq,count[char_right])
        

            window_size = right - left + 1
            if window_size  - max_freq > k:
                char_left = s[left]
                count[char_left] -= 1
                left += 1
            max_length = max(max_length, right - left + 1)

        return max_length    