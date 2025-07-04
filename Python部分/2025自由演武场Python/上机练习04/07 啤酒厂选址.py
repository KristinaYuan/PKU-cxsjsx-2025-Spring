n=int(input())
dist=[0 for i in range(n)]
beer=[0 for i in range(n)]
d=0
ans=0

for i in range(n):
    lst=input().split()
    beer[i]=int(lst[0])
    d+=int(lst[1])
    if i!=n-1:
        dist[i+1]=d

for i in range(n):
    ans+=dist[i]*beer[i]

for i in range(n):
    dist+=[dist[i]+d]

pos=0
for i in range(n):
    x=0
    for j in range(n):
        if j<i:
            x+=beer[j]*min(dist[i]-dist[j],dist[j+n]-dist[i])
        else:
            x+=beer[j]*min(dist[j]-dist[i],dist[i+n]-dist[j])
    if x<ans:
        pos=i
        ans=x

print(pos,end=",")
print(ans)
