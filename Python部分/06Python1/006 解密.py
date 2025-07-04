str=input()
def decipher(begin,end):
    if begin==end:
        print(str[begin],end="")
    elif begin+1==end:
        print(str[begin],end="")
        print(str[end],end="")
    else:
        a=int((begin+end)/2)
        decipher(begin+1,a)
        print(str[begin],end="")
        decipher(a+1,end)
decipher(0,len(str)-1)
