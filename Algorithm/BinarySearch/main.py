def BinarySearch(target, l, start=None, end=None):
    if not start:
        start = 0
    if not end:
        end = len(l) - 1

    if start > end:
        return -1

    mid = (start + end) // 2
    if l[mid] == target:
        return mid
    elif l[mid] > target:
        return BinarySearch(target, l, start, mid - 1)
    else:
        return BinarySearch(target, l, mid + 1, end)
