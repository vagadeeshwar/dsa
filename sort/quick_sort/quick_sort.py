# Select any pivot element and sort it in place ie everthing to the left of pivot should be less than it
# and everything to the right of it should be greater than it, partition() does this
# Call quick sort on the two halves described above without including the pivot in them
# hence an element(the pivot) of every subarr is sorted in place until every element of arr is sorted
def quick_sort(arr, start, end):  # impure
    if end - start <= 1:
        return

    pivot_idx = partition(arr, start, end)
    quick_sort(arr, start, pivot_idx)
    quick_sort(arr, pivot_idx + 1, end)


# pivot sorting as well quick_sort() done in place without using any copies
def partition(arr, start, end, pivot_idx=None):  # impure

    if pivot_idx == None:
        pivot_idx = start

    pivot = arr[pivot_idx]
    count = 0

    for i in range(start, end):
        if arr[i] < pivot:
            count += 1

    new_pivot_idx = start + count
    arr[pivot_idx], arr[new_pivot_idx] = arr[new_pivot_idx], arr[pivot_idx]

    i = start
    j = end - 1

    while i < new_pivot_idx:
        if arr[i] < pivot:
            i += 1
        else:
            while arr[j] >= pivot:
                j -= 1
            arr[j], arr[i] = arr[i], arr[j]
            j -= 1
            i += 1

    return new_pivot_idx
