import random


def main():
    a_len = 20
    array = []
    for i in range(a_len):
        array.append(random.randint(0, 200))
    nums = {}
    for num in array:
        if (not nums.get(num)):
            nums[num] = 1
            continue
        nums[num] += 1
    print(array)

    for num in nums:
        print('%6d : %d' % (num, nums[num]))


main()
