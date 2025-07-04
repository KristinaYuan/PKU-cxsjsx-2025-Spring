lst=input().split()
m,n=int(lst[0]),int(lst[1])
ans=int(0)
for i in range(m,n+1):
    if i%17==0:
        ans=ans+i
print(ans)
