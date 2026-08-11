# Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
# Output: [1, 2, 4, 3, 5, 0, 0, 0]
# Explanation: There are three 0s that are moved to the end.

# Input: arr[] = [10, 20, 30]
# Output: [10, 20, 30]
# Explanation: No change in array as there are no 0s.

# Input: arr[] = [0, 0]
# Output: [0, 0]
# Explanation: No change in array as there are all 0s.

# [Naive Approach] Using Temporary Array - O(n) Time and O(n) Space

def pushZerosToEnd(arr):
    n = len(arr)
    temp = [0] * n
    j = 0
    for i in range(n):
        if arr[i] != 0:
            temp[j] = arr[i]
            j += 1
    while j < n:
        temp[j] = 0
        j += 1
    for i in range(n):
        arr[i] = temp[i]


if __name__ == "__main__":
    arr = [1, 2, 0, 4, 3, 0, 5, 0]
    pushZerosToEnd(arr)

    for num in arr:
        print(num, end=" ")


# [Better Approach] Two Traversals-O(n) Time and O(1) space

def pushZerosToEnd(arr):

    count = 0
    for i in range(len(arr)):
        if arr[i] != 0:
            arr[count] = arr[i]
            count += 1
    while count < len(arr):
        arr[count] = 0
        count += 1


if __name__ == "__main__":
    arr = [1, 2, 0, 4, 3, 0, 5, 0]
    pushZerosToEnd(arr)
    for num in arr:
        print(num, end=" ")


# [Expected Approach] One Traversal-O(n) Time and O(1) space

def pushZerosToEnd(arr):
    count = 0
    
    for i in range(len(arr)):
        if arr[i] != 0:
            arr[i], arr[count] = arr[count], arr[i]
            count += 1

if __name__ == "__main__":
    arr = [1, 2, 0, 4, 3, 0, 5, 0]
    pushZerosToEnd(arr)
    for num in arr:
        print(num, end=" ")