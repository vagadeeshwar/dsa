# Keep arr in right hand -> Take arr[0] in left -> Take arr[1] in left and insert in right place -> so on..
# left hand cards are sorted within themselves || This is simulated within same arr


def ins_sort(l):  # impure
    n = len(l)

    for i in range(1, n):
        key = l[i]  # card to be inserted into left hand
        j = i - 1
        while j >= 0 and key < l[j]:  # checking every card left hand to find insertion spot
            l[j + 1] = l[j]
            j -= 1
        l[j + 1] = key


l = [float(i) for i in input("Enter the list: ").strip().split()]
ins_sort(l)
print(l)
