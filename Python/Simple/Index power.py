def index_power(array, n):
    if n == 0:
        return 1
    else:
        if n >= len (array):
            return -1
        else:
            return array[n]**n