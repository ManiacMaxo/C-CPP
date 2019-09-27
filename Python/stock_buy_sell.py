stocks = [100, 180, 260, 310, 40, 535, 695]


def find_max(start):
    a_max = 0
    pos = None
    a_len = len(stocks)
    for i in range(start, a_len):
        if(stocks[i] > a_max):
            a_max = stocks[i]
            pos = i
    return pos


def find_min(end):
    a_min = float('inf')
    pos = None
    a_len = len(stocks)
    for i in range(a_len):
        if (stocks[i] < a_min):
            a_min = stocks[i]
            pos = i
    return pos


def main():
    if (stocks == stocks.sort(reverse=True)):
        print('Stocks are decreasing')
        exit()
    s_min = float('inf')
    s_max = 0
    d_min = d_max = None
    s_len = len(stocks)
    d_max = find_max(0)
    d_min = find_min(0)
    j = s_len
    for i in range(s_len):
        if (d_max == i):
            d_max = find_max(i+1)
        if (d_min == j):
            d_min = find_min(j-1)
        j -= 1
    print(d_min, d_max)
    s_max = stocks[d_max]
    s_min = stocks[d_min]
    if (d_min < d_max):
        print('Maximum profit: ', s_max - s_min,
              '\t When you buy on day %d and sell on day %d', d_min, d_max)


main()
