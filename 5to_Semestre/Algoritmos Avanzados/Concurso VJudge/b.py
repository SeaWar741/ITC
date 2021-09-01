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

    


if __name__ == "__main__":
    main()