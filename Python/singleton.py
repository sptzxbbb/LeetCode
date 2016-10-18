class Singleton():
    def __new__(cls, *args, **kw):
        if not hasattr(cls, '_instance'):
            cls._instance = object.__new__(cls, *args, **kw)
        return cls._instance


class Foo(Singleton):
    a = 1


if __name__ == '__main__':
    p1 = Foo()
    p2 = Foo()
    p2.a = 2

    print(p1.a, p2.a)
