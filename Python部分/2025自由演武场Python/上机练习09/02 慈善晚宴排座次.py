n=int(input())
name=[]
money=[]
for i in range(n):
    lst=input().split()
    name+=[lst[0]]
    money+=[int(lst[1])]
for i in range(n):
    s=name[0]
    x=0
    p=0
    for j in range(n):
        if money[j]>x:
            s=name[j]
            x=money[j]
            p=j
        elif money[j]==x:
            if name[j][0]=='P' or name[j][0]=='K' or name[j][0]=='U':
                if name[p][0]!='P' and name[p][0]!='K' and name[p][0]!='U':
                    s=name[j]
                    p=j
    print(s,end=" ")
    print(x)
    money[p]=0
