def binary_search(l, begin, end, item):
    if begin == end:
        return -1
    mid = (begin + end) // 2
    if l[mid] == item:
        return mid
    elif item > l[mid]:
        return binary_search(l, mid + 1, end, item)
    elif item < l[mid]:
        return binary_search(l, begin, mid, item)


l = [float(i) for i in input("Enter the sorted list: ").strip().split()]
item = float(input("Enter the item to search for: "))
print(binary_search(l, 0, len(l), item))
