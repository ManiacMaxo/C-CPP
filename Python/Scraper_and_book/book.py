import re

read_book()


def read_book():
    with open('book.txt', 'r') as b:
        for line in b:
            for word in line.split():
                check(word)


def check(word):
    with open('verbs.txt', 'r') as f:
        lines = f.readlines()
        for line in lines:
            with open('ans.txt', 'a') as ans:
                if word in line and not line.split()[0] in ans.txt:
                    words = line.split()
                    for i in range(6):
                        ans.write(words[i] + ' ')
                    print >> ans
