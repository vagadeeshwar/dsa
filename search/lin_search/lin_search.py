def linear_search(l, item):
    for i, ele in enumerate(l):
        if ele == item:
            return i
    return -1


l = [float(i) for i in input("Enter the sorted list: ").strip().split()]
item = float(input("Enter the item to search for: "))
print(linear_search(l, 0, len(l), item))
