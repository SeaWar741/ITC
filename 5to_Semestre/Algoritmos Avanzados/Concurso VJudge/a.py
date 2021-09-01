def main():
    n = int(input())
    total = 0

    input_string = input()
    user_list = input_string.split()
    # convert each item to int type
    for i in range(len(user_list)):
        # convert each item to int type
        user_list[i] = int(user_list[i])
        total += user_list[i]

    user_list.sort(reverse = True)

    minCoins = 0

    halfValue = total / 2
    for i in range(len(user_list)):
        minCoins +=  user_list[i]
        if(minCoins > halfValue):
            print(i+1)
            break



if __name__ == "__main__":
    main()