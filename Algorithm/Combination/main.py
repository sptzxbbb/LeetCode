def n_get_m(n, m):
    if m == n:
        return 1
    elif m == 0:
        return 1
    else:
        return n_get_m(n - 1, m - 1) + n_get_m(n - 1, m)


if __name__ == '__main__':
    print(n_get_m(8, 3))
