#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import functools

class OnlyOne:
    class __OnlyOne:
        def __init__(self, args):
            "docstring"
            self.val = args

        def __str__(self):
            return repr(self) + self.val

    instance = None

    def __init__(self, args):
        if not OnlyOne.instance:
            OnlyOne.instance = OnlyOne.__OnlyOne(args)
        else:
            OnlyOne.instance.val = args

    def __getattr__(self, name):
        return getattr(self.instance, name)


def log(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kwargs):
            print("%s %s()" % (text, func.__name__))
            return func(*args, **kwargs)
        return wrapper
    return decorator


@log('execute')
def foo(name):
    print("%s is an awesome programmer!" % name)


def count():
    def f(k, l):
        def g():
            l.append(k*k)
            return l
        return g

    fs = []
    l = []
    for k in range(1, 4):
        fs.append(f(k, l))
    return fs


class A:
    num = 0

    def __init__(self):
        A.num += 1

    @staticmethod
    def foo():
        print("%i" % A.num)



def main():
    a = A()
    a.foo()
    b = A()
    b.foo()
    c = A()
    c.foo()


if __name__ == '__main__':
    main()
