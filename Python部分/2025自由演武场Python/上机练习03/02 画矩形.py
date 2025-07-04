lst=input().split()
m,n,c,x=int(lst[0]),int(lst[1]),lst[2],int(lst[3])
if x==1:
    for i in range (m):
        for j in range (n):
            print(c,end="")
        print()
else:
    for j in range (n):
        print(c,end="")
    print()
    for i in range (m-2):
        print(c,end="")
        for j in range (n-2):
            print(" ",end="")
        print(c)
    for j in range (n):
        print(c,end="")
