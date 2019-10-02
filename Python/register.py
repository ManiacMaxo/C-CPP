def main():
    register = {  # randomly genetated names
        1: 'Amiens',
        2: 'Cate',
        3: 'John',
        4: 'Jordan',
        5: 'Kendall',
        6: 'Lawrence',
        7: 'Lile',
        8: 'Piere',
        9: 'Tory',
        10: 'Warren',
    }
    while True:
        num = int(input('Enter Student Number: '))
        if(num > 0 and num < 11):
            break
        print('Number out of range!')
    print(register[num])


main()
