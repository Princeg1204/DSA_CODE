# Input: arr[] = [2, 2, 3, 1, 3, 2, 1, 1]
# Output: [1, 2]
# Explanation: The frequency of 1 and 2 is 3, which is more than floor n/3 (8/3 = 2).

# Input: arr[] = [-5, 3, -5]
# Output: [-5]
# Explanation: The frequency of -5 is 2, which is more than floor n/3 (3/3 = 1).

# Input: arr[] = [3, 2, 2, 4, 1, 4]
# Output: [ ]
# Explanation: There is no majority element.

# [Naive Approach] Using Nested Loops - O(n^2) Time and O(1) Space

def findMajority(arr):
    n = len(arr)
    res = []

    for i in range(n):
        cnt = 0
        for j in range(i, n):
            if arr[j] == arr[i]:
                cnt += 1
        if cnt > (n // 3):
            if len(res) == 0 or arr[i] != res[0]:
                res.append(arr[i])
        if len(res) == 2:
            if res[0] > res[1]:
                res[0], res[1] = res[1], res[0]
            break

    return res

if __name__ == "__main__":
    arr = [2, 2, 3, 1, 3, 2, 1, 1]
    res = findMajority(arr)
    for ele in res:
        print(ele, end=" ")


# [Expected Approach] Boyer-Moore’s Voting Algorithm - O(n) Time and O(1) Space

def findMajority(arr):
    n = len(arr)
    ele1, ele2 = -1, -1
    cnt1, cnt2 = 0, 0

    for ele in arr:
        if ele1 == ele:
            cnt1 += 1
        elif ele2 == ele:
            cnt2 += 1
        elif cnt1 == 0:
            ele1 = ele
            cnt1 += 1
        elif cnt2 == 0:
            ele2 = ele
            cnt2 += 1
        else:
            cnt1 -= 1
            cnt2 -= 1

    res = []
    cnt1, cnt2 = 0, 0
    for ele in arr:
        if ele1 == ele:
            cnt1 += 1
        if ele2 == ele:
            cnt2 += 1
    if cnt1 > n / 3:
        res.append(ele1)
    if cnt2 > n / 3 and ele1 != ele2:
        res.append(ele2)

    if len(res) == 2 and res[0] > res[1]:
        res[0], res[1] = res[1], res[0]

    return res

if __name__ == "__main__":
    arr = [2, 2, 3, 1, 3, 2, 1, 1]
    res = findMajority(arr)
    for ele in res:
        print(ele, end = " ")