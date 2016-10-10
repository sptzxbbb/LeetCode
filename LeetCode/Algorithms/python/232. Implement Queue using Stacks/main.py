class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.stack.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        self.stack.pop(0)

    def peek(self):
        """
        :rtype: int
        """
        if not self.empty():
            return self.stack[0]


    def empty(self):
        """
        :rtype: bool
        """
        return False if len(self.stack) else True
