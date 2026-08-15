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


# [Better Approach] Using Temporary Array - O(n) Time and O(n) Space

# Python Program to left rotate the array by d positions
# using temporary array

# Function to rotate array
def rotateArr(arr, d):
    n = len(arr)
    d %= n
    temp = [0] * n
    for i in range(n - d):
        temp[i] = arr[d + i]

    for i in range(d):
        temp[n - d + i] = arr[i]

    for i in range(n):
        arr[i] = temp[i]

if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6]
    d = 2

    rotateArr(arr, d)
    for i in range(len(arr)):
        print(arr[i], end=" ")


# [Expected Approach 1] Juggling Algorithm - O(n) Time and O(1) Space

# Python Code to left rotate an array using Reversal Algorithm

# Function to rotate an array by d elements to the left
def rotateArr(arr, d):
    n = len(arr)
    d %= n
    reverse(arr, 0, d - 1)
    reverse(arr, d, n - 1)
    reverse(arr, 0, n - 1)
def reverse(arr, start, end):
    while start < end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1

if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6]
    d = 2
    
    rotateArr(arr, d)
  
    for i in range(len(arr)):
        print(arr[i], end=" ")
