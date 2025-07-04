N=int(input())
cnt=[[] for i in range (105)]
for i in range (N):
    lst=input().split()
    for j in range (2,len(lst)):
        cnt[int(lst[j])]+=[int(lst[0])]
mx=0
p=0
for i in range (1,100):
    if len(cnt[i])>mx:
        mx=len(cnt[i])
        p=i
print(p)
cnt[p].sort()
x=cnt[p][0]
print(cnt[p][0],end="")
for i in range (1,mx):
    if cnt[p][i]!=x:
        print(" ",end="")
        print(cnt[p][i],end="")
        x=cnt[p][i]
