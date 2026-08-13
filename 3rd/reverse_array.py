# Input: arr[] = [1, 4, 3, 2, 6, 5]  
# Output:  [5, 6, 2, 3, 4, 1]
# Explanation: The first element 1 moves to last position, the second element 4 moves to second-last and so on.

# Input: arr[] = [4, 5, 1, 2]
# Output: [2, 1, 5, 4]
# Explanation: The first element 4 moves to last position, the second element 5 moves to second last and so on.

# [Naive Approach] Using a temporary array - O(n) Time and O(n) Space

def reverseArray(arr):
    n = len(arr)
    temp = [0] * n
    for i in range(n):
        temp[i] = arr[n - i - 1]
    for i in range(n):
        arr[i] = temp[i]

if __name__ == "__main__":
    arr = [1, 4, 3, 2, 6, 5]

    reverseArray(arr)
  
    for i in range(len(arr)):
        print(arr[i], end=" ")


# [Expected Approach - 1] Using Two Pointers - O(n) Time and O(1) Space

def reverseArray(arr):
    left = 0
    right = len(arr) - 1
    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1

if __name__ == "__main__":
    arr = [1, 4, 3, 2, 6, 5]

    reverseArray(arr)
  
    for i in range(len(arr)):
        print(arr[i], end=" ")


# [Expected Approach - 2] Using Single Pointer - O(n) Time and O(1) Space

def reverseArray(arr):
    n = len(arr)
    for i in range(n // 2):
        temp = arr[i]
        arr[i] = arr[n - i - 1]
        arr[n - i - 1] = temp

if __name__ == "__main__":
    arr = [1, 4, 3, 2, 6, 5]

    reverseArray(arr)
  
    for i in range(len(arr)):
        print(arr[i], end=" ")