# Input: arr[] = [-2, 6, -3, -10, 0, 2]
# Output: 180
# Explanation: The subarray with maximum product is [6, -3, -10] with product = 6 * (-3) * (-10) = 180.

# Input: arr[] = [-1, -3, -10, 0, 6]
# Output: 30
# Explanation: The subarray with maximum product is [-3, -10] with product = (-3) * (-10) = 30.

# Input: arr[] = [2, 3, 4] 
# Output: 24 
# Explanation: For an array with all positive elements, the result is product of all elements. 

# [Naive Approach] Using Two Nested Loops – O(n^2) Time and O(1) Space

def maxProduct(arr):
    n = len(arr)
    maxProd = arr[0]

    for i in range(n):
        mul = 1
        for j in range(i, n):
            mul *= arr[j]
            maxProd = max(maxProd, mul)
    
    return maxProd

if __name__ == "__main__":
    
    arr = [-2, 6, -3, -10, 0, 2]
    
    print(maxProduct(arr))

# [Expected Approach - 1] Track of Min and Max - O(n) Time and O(1) Space

def maxProduct(arr):

    n = len(arr)

    currMax = arr[0]
    currMin = arr[0]
    maxProd = arr[0]
    for i in range(1, n):

        temp = max(arr[i], arr[i] * currMax, arr[i] * currMin)

        currMin = min(arr[i], arr[i] * currMax, arr[i] * currMin)

        currMax = temp

        maxProd = max(maxProd, currMax)

    return maxProd


if __name__ == "__main__":
    
    arr = [-2, 6, -3, -10, 0, 2]
    
    print(maxProduct(arr))
