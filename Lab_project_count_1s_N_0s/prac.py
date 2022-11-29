from goto import goto, label
def stringCount(str):
    # count no of 1's and 0's
    count0=0
    count1=0
    for i in range(len(str)):
        if str[i]=='0':
            count0+=1
        else:
            count1+=1

    # print(count0,count1)
    print("No of 0's:",count0)
    print("No of 1's:",count1)

# Input
str = input("Enter a string: ")
n = len(str)
count = 0
# check if only 0s and 1s are given in the input
while count < n:
    l = str[count]
    if (l!='0' and l!='1'):
        print("!!!Invalid Input...Enter ONLY 0's and 1's : ")
        # exit()
        goto .end
    count+=1

print("String is:",str)
stringCount(str)

label .end