d=int(input())
n=int(input())
trash=[[0 for i in range(1025)] for i in range(1025)]
bomb=[[0 for i in range(1025)] for i in range(1025)]
for i in range(n):
    lst=input().split()
    x=int(lst[0])
    y=int(lst[1])
    k=int(lst[2])
    trash[x][y]=k
    for p in range(x-d,x+d+1):
        if p>=0 and p<1025:
            for q in range(y-d,y+d+1):
                if q>=0 and q<1025:
                    bomb[p][q]+=k
mx=0
ans=0
for i in range(1025):
    for j in range(1025):
        if bomb[i][j]>mx:
            mx=bomb[i][j]
            ans=1
        elif bomb[i][j]==mx:
            ans+=1
print(ans,end=" ")
print(mx)
