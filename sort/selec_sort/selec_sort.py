def selec_sort(l):
    n = len(l)

    for i in range(n - 1):
        idx = i
        for j in range(i, n):
            if l[j] < l[idx]:
                idx = j
        l[i], l[idx] = l[idx], l[i]


l = [float(i) for i in input("Enter the list: ").strip().split()]
selec_sort(l)
print(l)
