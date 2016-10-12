class Student():
    def __init__(self, name):
        "docstring"
        self.name = name

    def __call__(self):
        print("My name is %s" % self.name)


if __name__ == '__main__':
    s = Student('Peter')
    s()
