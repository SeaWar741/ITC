def main():
    flag = False

    input_string = input()

    cnt=0
    i=0

    while(input_string[i]!='\0' and i < (len(input_string)-1)):
        if(input_string[i]=='1'):
            while(input_string[i]=='1'):
                cnt+=1
                i+=1
        else:
            while(input_string[i]=='0'):
                cnt+=1
                i+=1
        if(cnt>=7):
            flag=True
            break
        cnt=0

    if(flag):
        print("YES")
    else:
        print("NO")
    


if __name__ == "__main__":
    main()