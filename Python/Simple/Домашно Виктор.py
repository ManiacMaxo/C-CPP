inputNumber = 65535

def numToList(num):
    res = []
    while num:
        res.insert(0, num % 10)
        num = num // 10
    return res

print(numToList(inputNumber))