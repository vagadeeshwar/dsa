# Swap if arr[0]>arr[1] and Swap if arr[1]>arr[2]... -> ...Swap if arr[-3]>arr[-2] -> so on...
# arr[-1] is sorted -> arr[-2:] is sorted -> so on...


def bubble_sort(l):  # impure
    n = len(l)

    for i in range(n - 1):
        already_sorted = True
        for j in range(n - i - 1):
            if l[j] > l[j + 1]:
                l[j], l[j + 1] = l[j + 1], l[j]
                already_sorted = False
        if already_sorted:
            break  # If there were no swaps during the last iteration,the array is already sorted, and you can terminate


l = [float(i) for i in input("Enter the list: ").strip().split()]
bubble_sort(l)
print(l)
