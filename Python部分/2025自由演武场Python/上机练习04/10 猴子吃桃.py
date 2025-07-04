n=int(input())
a=1
while True:
    flag=1
    s=a
    for i in range(n-1):
        s*=n
        s+=1
        if s%(n-1)!=0:
            flag=0
            break
        else:
            s=int(s/(n-1))
    if flag==0:
        a+=1
    else:
        print(s*n+1)
        break
