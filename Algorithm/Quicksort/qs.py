#! /usr/bin/env python3
# -*- coding: utf-8 -*-


def partition(arr, start, end):
    pivot = arr[end]
    k = start
    for j in range(start, end):
        if arr[j] < pivot:
            arr[j], arr[k] = arr[k], arr[j]
            k += 1
    arr[k], arr[end] = arr[end], arr[k]
    return k


def quicksort(arr, start, end):
    if start >= end:
        return
    else:
        pivot_pos = partition(arr, start, end)
        quicksort(arr, start, pivot_pos - 1)
        quicksort(arr, pivot_pos + 1, end)


def main():
    arr = [3, 7, 8, 9, 5, 2, 1, 9, 5, 4]
    quicksort(arr, 0, len(arr) - 1)
    print(arr)


if __name__ == '__main__':
    main()
