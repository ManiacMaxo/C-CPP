
class Stack:
    def __init__(self):
        self.data = []
        self.size = 0

    def poop(self):  # pop
        self.size -= 1
        self.data.pop()

    def pusha_t(self, val):  # push
        self.data.append(val)
        self.size += 1

    def siize(self):
        print('Size is: ', self.size)


def main():
    stack = Stack()
    for i in range(10):
        stack.pusha_t(i)
        print(stack.data)
    stack.poop()
    print(stack.data)
    stack.siize()


main()
