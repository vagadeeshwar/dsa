# Divide arr into 2 equal halves every call until len(arr)=1
# Merge arrays while returning from the recursion tree ie 1 element arrs
# are merged to form 2 element arrs and so on
def merge_sort(l):  # impure
    n = len(l)

    if n == 1:
        return l

    mid = n // 2
    merge(merge_sort(l[:mid]), merge_sort(l[mid:]), l)
    return l


# Merge two sorted arrays l1 and l2 into l
def merge(l1, l2, l):  # impure
    m = len(l1)
    n = len(l2)
    i = 0
    j = 0
    k = 0

    while i < m and j < n:
        if l1[i] <= l2[j]:
            l[k] = l1[i]
            i += 1
            k += 1
        else:
            l[k] = l2[j]
            j += 1
            k += 1
    if i == m:
        l[k:] = l2[j:]
    else:
        l[k:] = l1[i:]


l = [float(i) for i in input("Enter the list: ").strip().split()]
merge_sort(l)
print(l)
