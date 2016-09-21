#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import glob

def create_file():
    for i in range(10):
        filename = str(i) + ".txt"
        open(filename, "w")
    return


def main():
    files = glob.glob('./**/*.txt', recursive=True)
    list(map(os.remove, files))


if __name__ == '__main__':
    main()
