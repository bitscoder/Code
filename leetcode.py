def maximumTripletValue(self, nums):
        ans = 0
        n = len(nums)

        if n < 3:
            return ans

        a = nums[0]
        b = nums[1]
        d = nums[0]
        p = nums[1]
        for i in range(2, n):
            current_value = (a - b) * nums[i]
            ans = max(ans, current_value)
            print(ans, a, b, nums[i])

            if (b - nums[i]) > (a - nums[i]):
                if (b - nums[i]) > (a - b):
                    a, b = b, nums[i]
                    if d > a:
                         a = d
            else:
                if (a - nums[i]) > (a - b):
                    b = nums[i]
                    if d > a:
                         a = d
            if (d - p) > (a - b):
                 a,b = d,p
            d = max(d, nums[i])
            p = nums[i]
            

        return ans
print(maximumTripletValue(1, [8,6,3,13,2,12,19,5,19,6,10,11,9]))
#[8,6,3,13,2,12,19,5,19,6,10,11,9]
# 114
# 266
