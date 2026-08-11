# Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
# Output: 11
# Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.

# Input: arr[] = [-2, -4]
# Output: -2
# Explanation: The subarray [-2] has the largest sum -2.

# Input: arr[] = [5, 4, 1, 7, 8]
# Output: 25
# Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.

# [Naive Approach] By iterating over all subarrays - O(n^2) Time and O(1) Space

def maxSubarraySum(arr):
    res = arr[0]
    for i in range(len(arr)):
        currSum = 0
        for j in range(i, len(arr)):
            currSum = currSum + arr[j]
            res = max(res, currSum)
          
    return res

if __name__ == "__main__":
    arr = [2, 3, -8, 7, -1, 2, 3]
    print(maxSubarraySum(arr))


# [Expected Approach] Using Kadane's Algorithm - O(n) Time and O(1) Space

def maxSubarraySum(arr):
    res = arr[0]
    maxEnding = arr[0]

    for i in range(1, len(arr)):
        maxEnding = max(maxEnding + arr[i], arr[i])
        res = max(res, maxEnding)
    
    return res

if __name__ == "__main__":
    arr = [2, 3, -8, 7, -1, 2, 3]
    print(maxSubarraySum(arr))
