import re
import time


def read_book():
    with open('book.txt', 'r') as b:
        for line in b:
            for word in line.split():
                print word
                check(word)


def check(word):
    with open('verbs.txt', 'r') as f:
        lines = f.readlines()
        for line in lines:
            words = line.split()
            num = 0
            for _ in words:
                if word == words[num]:
                    with open('ans.txt', 'a') as a:
                        for i in range(6):
                            print words[i]
                            a.write(words[i] + ' ')
                        print >> a
                    return
                num += 1


read_book()
