lst=input().split()
x,y,c=int(lst[0]),int(lst[1]),lst[2]
a=0
if c=="+":
    a=x+y
    print(a)
elif c=="-":
    a=x-y
    print(a)
elif c=="*":
    a=x*y
    print(a)
elif c=="/":
    if y==0:
        print("Divided by zero!")
    else:
        a=int(x/y)
        print(a)
else:
    print("Invalid operator!")
