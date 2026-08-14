# Input: arr[] = [1, 2, 3, 4, 5, 6], d = 2
# Output: [3, 4, 5, 6, 1, 2]
# Explanation: After first left rotation, arr[] becomes [2, 3, 4, 5, 6, 1] and after the second rotation, arr[] becomes [3, 4, 5, 6, 1, 2]

# Input: arr[] = [1, 2, 3], d = 4
# Output: [2, 3, 1]
# Explanation: The array is rotated as follows:

# After first left rotation, arr[] = [2, 3, 1]
# After second left rotation, arr[] = [3, 1, 2]
# After third left rotation, arr[] = [1, 2, 3]
# After fourth left rotation, arr[] = [2, 3, 1]

# [Naive Approach] Rotate One by One - O(n * d) Time and O(1) Space

# Python Program to left rotate the array by d positions
# by rotating one element at a time

# Function to left rotate array by d positions
def rotateArr(arr, d):
    n = len(arr)
    for i in range(d):
        first = arr[0]
        for j in range(n - 1):
            arr[j] = arr[j + 1]
        arr[n - 1] = first

if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6]
    d = 2

    rotateArr(arr, d)

    for i in range(len(arr)):
        print(arr[i], end=" ")
