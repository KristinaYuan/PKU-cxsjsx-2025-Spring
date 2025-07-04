lst=input().split()
n,x,y=int(lst[0]),int(lst[1]),int(lst[2])
if y<x*n:
    print(int(n - y / x))
else:
    print(0)
