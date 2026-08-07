# Input: arr[] = [2, -3, 4, 1, 1, 7]
# Output: 3
# Explanation: 3 is the smallest positive number missing from the array.

# Input: arr[] = [5, 3, 2, 5, 1]
# Output: 4
# Explanation: 4 is the smallest positive number missing from the array.

# Brute Force Approach: By Sorting - O(n*log n) Time and O(1) Space

def missingNumber(arr):
    arr.sort()
    res = 1
    for num in arr:

        if num == res:
            res += 1
        elif num > res:
            break
    return res


if __name__ == "__main__":

    arr = [2, -3, 4, 1, 1, 7]
    print(missingNumber(arr))

# Better approach Using Visited Array - O(n) Time and O(n) Space    

def missingNumber(arr):
    n = len(arr)
    vis = [False] * n
    for i in range(n):
        if 0 < arr[i] <= n:
            vis[arr[i] - 1] = True
    for i in range(1, n + 1):
        if not vis[i - 1]:
            return i
    return n + 1

if __name__ == "__main__":
    arr = [2, -3, 4, 1, 1, 7]
    print(missingNumber(arr))


# // Optimal Approach Using Cycle Sort - O(n) Time and O(1) Space    

def missingNumber(arr):

    n = len(arr)
    for i in range(n):
        while 1 <= arr[i] <= n and arr[i] != arr[arr[i] - 1]:
            temp = arr[i]
            arr[i] = arr[arr[i] - 1]
            arr[temp - 1] = temp
    for i in range(1, n + 1):
        if i != arr[i - 1]:
            return i
    return n + 1

if __name__ == '__main__':
    arr = [2, -3, 4, 1, 1, 7]
    print(missingNumber(arr))