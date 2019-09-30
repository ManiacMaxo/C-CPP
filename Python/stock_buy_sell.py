stocks = [100, 180, 260, 310, 40, 535, 695]


def find_min_max(start, end):
    a_min = float('inf')
    a_max = 0
    pos = []
    for i in range(start, end):
        if (stocks[i] < a_min):
            a_min = stocks[i]
            pos[0] = i
        if (stocks[i] > a_max):
            a_max = stocks[i]
            pos[1] = i
    return pos


def main():
    if (stocks == stocks.sort(reverse = True)):
        print('Stocks are decreasing')
        exit()
    a_len = len(stocks)
    day = find_min_max(0, a_len)
    print(day[0], day[1])
    if (day[0] > day[1]):
        from_maxes = find_min_max(0, day[1]) # smallest number b4 max
        from_mins = find_min_max(day[0], a_len) # largest number after min
        if(stocks[from_maxes[1]] - stocks[from_maxes[0]] > stocks[from_mins[1]] - stocks[from_mins[0]]):
            day[0] = from_maxes[0]
            day[1] = from_maxes[1]
        else:
            day[0] = from_mins[0]
            day[1] = from_mins[1]
    print('Maximum profit: %d\t When you buy on day %d and sell on day %d' % (stocks[day[1]] - stocks[day[0]], day[0], day[1]))


main()
