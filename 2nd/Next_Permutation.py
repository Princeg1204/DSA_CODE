# Input: arr[] = [2, 4, 1, 7, 5, 0]
# Output: [2, 4, 5, 0, 1, 7]
# Explanation: The next lexicographically greater arrangement of the elements in the array arr[] is [2, 4, 5, 0, 1, 7].

# Input: arr[] = [3, 2, 1]
# Output: [1, 2, 3]
# Explanation: This is the last permutation, so we return the lowest possible permutation (ascending order).

# Input: arr[] = [1, 3, 5, 4, 2]
# Output: [1, 4, 2, 3, 5]
# Explanation: The next lexicographically greater arrangement of the elements in the array arr[] is [1, 4, 2, 3, 5].

# [Naive Approach] Generate All Permutations - O(n! * n) Time and O(n! * n) Space

# Function to generate all possible permutations
def generatePermutations(res, arr, idx):
    if idx == len(arr) - 1:
        res.append(arr[:])
        return
    for i in range(idx, len(arr)):
        arr[idx], arr[i] = arr[i], arr[idx]
        generatePermutations(res, arr, idx + 1)
        arr[idx], arr[i] = arr[i], arr[idx]

def nextPermutation(arr):

    res = []
    generatePermutations(res, arr, 0)
    res.sort()
    for i in range(len(res)):
        if res[i] == arr:
            if i < len(res) - 1:
                arr[:] = res[i + 1]
            else:
                arr[:] = res[0]
            break

if __name__ == "__main__":

    arr = [2, 4, 1, 7, 5, 0]

    nextPermutation(arr)

    for x in arr:
        print(x, end=" ")

# [Expected Approach] Generating Only Next - O(n) Time and O(1) Space

def nextPermutation(arr):
    n = len(arr)
    pivot = -1
    for i in range(n - 2, -1, -1):
        if arr[i] < arr[i + 1]:
            pivot = i
            break
    if pivot == -1:
        arr.reverse()
        return
    for i in range(n - 1, pivot, -1):
        if arr[i] > arr[pivot]:
            arr[i], arr[pivot] = arr[pivot], arr[i]
            break
    left, right = pivot + 1, n - 1
    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1

if __name__=="__main__":
    arr = [ 2, 4, 1, 7, 5, 0 ]
    nextPermutation(arr)
    
    print(" ".join(map(str, arr)))


