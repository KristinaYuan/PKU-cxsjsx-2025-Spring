n=int(input())
a=[]
b=[]
for i in range(n):
    lst=input().split()
    if lst[0]=='male':
        a+=[float(lst[1])]
    else:
        b+=[float(lst[1])]
a.sort()
b.sort()
for i in range(len(a)):
    print("%.2f"%a[i],end=" ")
for i in range(len(b)-1):
    print("%.2f"%b[len(b)-1-i],end=" ")
print("%.2f"%b[0])
